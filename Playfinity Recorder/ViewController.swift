//
//  ViewController.swift
//  Playfinity Recorder
//
//  Created by Stian Vælitalo on 30/09/2018.
//  Copyright © 2018 Stian Vælitalo. All rights reserved.
//

import UIKit
import puffin_sdk

class ViewController: UIViewController {

	@IBOutlet var infoButton: UIButton!
	
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
					
					PFISDKManager.shared?.soundsManager.play(settings: self.throwsound)
				}
				
				
				if event.eventType == .caught {
					self.infoButton.setTitle("Catch!", for: UIControl.State.normal)
					_ = Timer.scheduledTimer(withTimeInterval: 1.0, repeats: false, block: { (timer) in
						self.infoButton.setTitle("Ball is ready. Throw it!", for: UIControl.State.normal)
					})
					
					PFISDKManager.shared?.soundsManager.play(settings: self.catchsound)
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
		
		let conf = PFIConfiguration.init(applicationKey: appId, developerId: devId)
		PFISDKManager.with(config: conf, completion: { (sdk, err) in
			if let e = err {
				NSLog("Framework not initialized: \(e)")
				self.infoButton.setTitle("Framework initialization failed!", for: UIControl.State.normal)
			} else {
				NSLog("Framework successfully initialized")
				self.infoButton.setTitle("Framework initialized", for: UIControl.State.normal)
				
				// Listening for console set up as ball
				PFISDKManager.shared?.discover(types: SensorType.ball, delegate: self, forOad: false, clearCache: true)
			}
		})
		
		NSLog("View did load")
	}


}

extension ViewController: SensorConfiguratorDelegate {
	func didConfigure(sensor: Sensor) {
		NSLog("Did configure sensor as ball: \(sensor.description())")
		self.infoButton.setTitle("Ball is ready. Throw it!", for: UIControl.State.normal)
		
		if let ps = sensor as? PFIBallSensor, aBall == nil {
			aBall = ps
		}
	}
	
	func didFail(error: Error) {
		NSLog("Failed disconvering ball: \(error)")
		self.infoButton.setTitle("Failed. \(error)", for: UIControl.State.normal)
	}
	
	func oadMode(sensor: Sensor) {
	}
}
