//
//  PlayfinityViewController.swift
//  PlayfinityKitExample
//
//  Created by playfinity on 12/04/2020.
//  Copyright © 2020 io.playfinity. All rights reserved.
//

import UIKit
import PlayfinityKit

class PlayfinityViewController: UIViewController {

    lazy var stackView: UIStackView = {
        let view = UIStackView()
        view.axis = .vertical
        view.translatesAutoresizingMaskIntoConstraints = false
        return view
    }()

    lazy var statusView: StatusView = {
        let view = StatusView()
        return view
    }()

    lazy var sensorView: SensorView = {
        let view = SensorView()
        return view
    }()

    lazy var counterView: CounterView = {
        let view = CounterView()
        view.eventName = eventName
        return view
    }()

    lazy var eventLogView: EventLogView = {
        let view = EventLogView.init()
        return view
    }()

    var sdk: PlayfinityKit! {
        didSet {
            statusView.statusText = "STATUS: CONNECTED"
        }
    }

    let player: SoundsPlayer = SoundsPlayer()
    let config: Configuration
    let eventName: String

    init(type: SensorType, eventName: String) {
        self.eventName = eventName
        self.config = Configuration(applicationKey: "SAMPLE_TEST", developerId: "SAMPLE_TEST", sensorType: type)
        super.init(nibName: nil, bundle: nil)
    }

    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }

    override func loadView() {
        super.loadView()
        view.backgroundColor = .lightGray
        title = "Playfinity Example"
        setupStackView()
        setupStatusView()
        setupSensorView()
        setupCounterView()
        setupEventLog()
    }

    func setupStackView() {
        view.addSubview(stackView)
        let margins = view.safeAreaLayoutGuide
        stackView.topAnchor.constraint(equalTo: margins.topAnchor, constant: 5).isActive = true
        stackView.leadingAnchor.constraint(equalTo: margins.leadingAnchor, constant: 5).isActive = true
        stackView.trailingAnchor.constraint(equalTo: margins.trailingAnchor, constant: -5).isActive = true
        stackView.bottomAnchor.constraint(equalTo: margins.bottomAnchor, constant: 0).isActive = true
    }

    func setupStatusView() {
        statusView.heightAnchor.constraint(equalToConstant: 78).isActive = true
        stackView.addArrangedSubview(statusView)
        stackView.setCustomSpacing(5, after: statusView)
    }

    func setupSensorView() {
        sensorView.heightAnchor.constraint(equalToConstant: 120).isActive = true
        stackView.addArrangedSubview(sensorView)
        stackView.setCustomSpacing(5, after: sensorView)
    }

    func setupCounterView() {
        counterView.heightAnchor.constraint(equalToConstant: 40).isActive = true
        stackView.addArrangedSubview(counterView)
        stackView.setCustomSpacing(5, after: counterView)
    }

    func setupEventLog() {
        stackView.addArrangedSubview(eventLogView)
    }

    override func viewDidLoad() {
        super.viewDidLoad()

        PlayfinityKit.validate(configuration: config) { [weak self] (result) in
            guard let self = self else { return }
            switch result {
            case .success(let sdk):
                self.sdk = sdk
                print("sdk: \(sdk)")
                self.didValidatedSDK(sdk)
            case .failure(let error):
                print("error: \(error)")
            }
        }
    }

    func didValidatedSDK(_ sdk: PlayfinityKit) {

    }
}
