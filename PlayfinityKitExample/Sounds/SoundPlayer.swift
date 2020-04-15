//
//  SoundPlayer.swift
//  PlayfinityKitExample
//
//  Created by playfinity on 11/04/2020.
//  Copyright © 2020 io.playfinity. All rights reserved.
//

import UIKit
import AVFoundation

class SoundsPlayer {

    private var player: AVAudioPlayer?

    init() {
        try! AVAudioSession.sharedInstance().setCategory(AVAudioSession.Category.playback)
        try! AVAudioSession.sharedInstance().setActive(true)
    }

    func playThrow() {
        let i = Int.random(in: 1..<5)
        let fileName: String = "throw_v5_level1_\(i)"
        playSound(fileName: fileName)
    }

    func playJump() {
        let i = Int.random(in: 1..<5)
        let fileName: String = "jump_v5_level1_\(i)"
        playSound(fileName: fileName)
    }

    private func playSound(fileName: String) {
        if let sound = NSDataAsset(name: fileName) {
            do {
                let player: AVAudioPlayer = try AVAudioPlayer(data: sound.data, fileTypeHint: "wav")
                self.player = player
                player.play()
            } catch let error {
                print("play sound got error \(error.localizedDescription)")
            }
        }
    }
}
