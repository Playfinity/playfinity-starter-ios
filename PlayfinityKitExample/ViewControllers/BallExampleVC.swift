//
//  BallExample.swift
//  PlayfinityKitExample
//
//  Created by playfinity on 10/04/2020.
//  Copyright © 2020 io.playfinity. All rights reserved.
//

import UIKit
import PlayfinityKit
import AVFoundation

class BallExampleViewController: PlayfinityViewController {

    override func didValidatedSDK(_ sdk: PlayfinityKit) {
        sdk.addObserver(self)
        sdk.scan()
    }

    func handleThrowEvent(speed: Double) {
        counterView.counter = counterView.counter + 1
        eventLogView.clear()

        let speedText = String(format: "%.3f", speed)
        let text = "Speed: \(speedText)km/h"
        eventLogView.add(eventLog: .init(title: "Throw", bottomText: text))
        player.playThrow()
    }

    func handleEvent(name: String, airtime: Double, height: Double) {
        let airtimeText = String(format: "%.2f", airtime / 1000)
        let height = String(format: "%.2f", height)

        let eventText = "Airtime: \(airtimeText)sec height: \(height)cm\n"
        eventLogView.add(eventLog: .init(title: name, bottomText: eventText))
    }

}

extension BallExampleViewController: SensorObserver {

    func playfinityKit(_ playfinityKit: PlayfinityKit, lowBatteryOn sensor: Sensor) {

    }

    func playfinityKit(_ playfinityKit: PlayfinityKit, didFoundSensor sensor: Sensor) {
        print("found sensor: \(sensor.name)")

        sensorView.sensorName = sensor.name
        sensorView.sensorId = sensor.id
        sensorView.firmwareVersion = sensor.firmware
    }

    func playfinityKit(_ playfinityKit: PlayfinityKit, didGetEvent event: BallEvent, onSensor sensor: Sensor) {
        print("got event \(event) on sensor: \(sensor.name)")
        switch event {
        case .throwEvent(let speed):
            handleThrowEvent(speed: speed)
        case .bounceEvent(let airtime, let height):
            handleEvent(name: "Bounce", airtime: airtime, height: height)
        case .missEvent(let airtime, let height):
            handleEvent(name: "Miss", airtime: airtime, height: height)
        case .catchEvent(let airtime, let height):
            handleEvent(name: "Catch", airtime: airtime, height: height)
        case .buttonPressEvent:
            eventLogView.add(eventLog: .init(title: "ButtonPress", bottomText: "-"))
        }
    }
}
