//
//  ViewController.swift
//  PlayfinityKitExample
//
//  Created by playfinity on 10/04/2020.
//  Copyright © 2020 io.playfinity. All rights reserved.
//

import UIKit
import PlayfinityKit
class ViewController: UIViewController {

    @IBAction func ballExample(sender: Any) {
        let vc = BallExampleViewController.init(type: .ball, eventName: "throws")
        navigationController?.pushViewController(vc, animated: true)
    }

    @IBAction func trampolineExample(sender: Any) {
        let vc = TrampolineExampleVC.init(type: .trampoline, eventName: "jumps")
        navigationController?.pushViewController(vc, animated: true)
    }

    @IBAction func footballExample(sender: Any) {
        let vc = FootballExampleVC.init(type: .trampoline, eventName: "kicks")
        navigationController?.pushViewController(vc, animated: true)
    }
}

