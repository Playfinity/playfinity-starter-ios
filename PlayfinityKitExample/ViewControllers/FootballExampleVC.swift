//
//  FootballExample.swift
//  PlayfinityKitExample
//
//  Created by playfinity on 14/04/2020.
//  Copyright © 2020 io.playfinity. All rights reserved.
//

import UIKit
import PlayfinityKit

class FootballExampleVC: PlayfinityViewController {

    override func didValidatedSDK(_ sdk: PlayfinityKit) {
        sdk.addObserver(self)
        sdk.scan()
    }

    func handleKick(with speed: Double) {
        counterView.counter = counterView.counter + 1
        eventLogView.clear()
        eventLogView.add(eventLog: .init(title: "Kick", bottomText: "-"))
        player.playJump()
    }
}

extension FootballExampleVC: SensorObserver {

    func playfinityKit(_ playfinityKit: PlayfinityKit, lowBatteryOn sensor: Sensor) { }

    func playfinityKit(_ playfinityKit: PlayfinityKit, didFoundSensor sensor: Sensor) {
        print("found sensor: \(sensor.name)")
        sensorView.sensorName = sensor.name
        sensorView.sensorId = sensor.id
        sensorView.firmwareVersion = sensor.firmware
    }

    func playfinityKit(_ playfinityKit: PlayfinityKit, didGetEvent event: FootballEvent, onSensor sensor: Sensor) {
        print("got event \(event) on sensor: \(sensor.name)")
        switch event {
        case .kickEvent(let speed):
            handleKick(with: speed)
        case .missEvent:
            eventLogView.add(eventLog: .init(title: "Miss", bottomText: "-"))
        case .bounceEvent:
            eventLogView.add(eventLog: .init(title: "Bounce", bottomText: "-"))
        case .buttonPressEvent:
            eventLogView.add(eventLog: .init(title: "ButtonPress", bottomText: "-"))
        }
    }
}
