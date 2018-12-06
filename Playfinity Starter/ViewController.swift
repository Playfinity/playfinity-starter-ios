//
//  ViewController.swift
//  Playfinity Recorder
//
//  Created by Stian Vælitalo on 30/09/2018.
//  Copyright © 2018 Stian Vælitalo. All rights reserved.
//

import UIKit
import playfinity_sdk
import playfinity_sounds

class ViewController: UIViewController {

	@IBOutlet var infoButton: UIButton!
	
	var sdk: PlayfinitySDK?
	
	let throwsound = PlaySoundSettings.custom(file: "throw", ext: "wav", loop: false, volume: SoundsVolumeType.max, balance: SoundsPanType.center, willBlockPlaybackUntilFinished: false)
	
	let catchsound = PlaySoundSettings.custom(file: "catch", ext: "wav", loop: false, volume: SoundsVolumeType.max, balance: SoundsPanType.center, willBlockPlaybackUntilFinished: false)
	
	var aBall: PFIBallSensor? {
		didSet {
			NSLog("Subscribing to ball events")
			aBall?.subscribeToBallEvents(completion: { (event) in
				if event.eventType == .thrown {
					self.infoButton.setTitle("Throw!", for: UIControl.State.normal)
					_ = Timer.scheduledTimer(withTimeInterval: 1.0, repeats: false, block: { (timer) in
						self.infoButton.setTitle("Ball is ready. Throw it!", for: UIControl.State.normal)
					})
					
					PFISoundsManager.shared.play(settings: self.throwsound)
				}
				
				
				if event.eventType == .caught {
					self.infoButton.setTitle("Catch!", for: UIControl.State.normal)
					_ = Timer.scheduledTimer(withTimeInterval: 1.0, repeats: false, block: { (timer) in
						self.infoButton.setTitle("Ball is ready. Throw it!", for: UIControl.State.normal)
					})
					
					PFISoundsManager.shared.play(settings: self.catchsound)
				}
			})

		}
	}
	
	override func viewDidLoad() {
		super.viewDidLoad()
		// Do any additional setup after loading the view, typically from a nib.
		
		// Register at labs@playfinity.io
		let devId = "SAMPLE_TEST"
		let appId = "SAMPLE_TEST"
		// In addition, the app's bundle identifier must be registered with Playfinity server
		
		let conf = PFIConfiguration.init(applicationKey: appId, developerId: devId, sensorType: SensorType.ball)
		PlayfinitySDK.validate(config: conf) { (sdk, error) in
			if let e = error {
				NSLog("Framework not initialized: \(e)")
				self.infoButton.setTitle("Framework initialization failed!", for: UIControl.State.normal)
			} else {
				NSLog("Framework successfully initialized")
				self.infoButton.setTitle("But ball close to phone", for: UIControl.State.normal)
				
				self.sdk = sdk
				
				// Listening for console set up as ball
				self.sdk?.scanForSensors(completion: { (sensors, er) in
					if let er = er {
						NSLog("Failed scanning for sensors \(er)")
					}
					
					for s in sensors {
						NSLog("Found ball sensor \(s.givenName)")
						if let ps = s as? PFIBallSensor, self.aBall == nil {
							self.aBall = ps
							self.infoButton.setTitle("Ball is ready. Throw it!", for: UIControl.State.normal)
						}
					}
				})
			}
		}
		
		NSLog("View did load")
	}


}
