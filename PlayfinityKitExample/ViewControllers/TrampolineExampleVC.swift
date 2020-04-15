//
//  TrampolineExample.swift
//  PlayfinityKitExample
//
//  Created by playfinity on 10/04/2020.
//  Copyright © 2020 io.playfinity. All rights reserved.
//

import Foundation
import PlayfinityKit

class TrampolineExampleVC: PlayfinityViewController {

    override func didValidatedSDK(_ sdk: PlayfinityKit) {
        sdk.addObserver(self)
        sdk.scan()
    }

    func handleJumpEvent() {
        counterView.counter = counterView.counter + 1
        eventLogView.clear()
        eventLogView.add(eventLog: .init(title: "Jump", bottomText: "-"))
        player.playJump()
    }

    func handleLandFeetEvent(yawRotation: Double, pitchRotation: Double) {
        print("yawRotation: \(yawRotation) pitchRotation: \(pitchRotation)")
        let eventText = "LandFeet yawRotation: \(yawRotation) pitchRotation: \(pitchRotation)cm\n"
        eventLogView.add(eventLog: .init(title: "LandFeet", bottomText: eventText))
    }
}

extension TrampolineExampleVC: SensorObserver {

    func playfinityKit(_ playfinityKit: PlayfinityKit, lowBatteryOn sensor: Sensor) { }

    func playfinityKit(_ playfinityKit: PlayfinityKit, didFoundSensor sensor: Sensor) {
        print("found sensor: \(sensor.name)")
        sensorView.sensorName = sensor.name
        sensorView.sensorId = sensor.id
        sensorView.firmwareVersion = sensor.firmware }

    func playfinityKit(_ playfinityKit: PlayfinityKit, didGetEvent event: TrampolineEvent, onSensor sensor: Sensor) {

        switch event {
        case .jumpEvent:
            handleJumpEvent()
        case .landFeetEvent(let yawRotation, let pitchRotation):
            handleLandFeetEvent(yawRotation: yawRotation, pitchRotation: pitchRotation)
        case .buttonPressEvent:
            eventLogView.add(eventLog: .init(title: "ButtonPress", bottomText: "-"))
        }

    }
}
