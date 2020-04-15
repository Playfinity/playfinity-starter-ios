//
//  SensorView.swift
//  PlayfinityKitExample
//
//  Created by playfinity on 14/04/2020.
//  Copyright © 2020 io.playfinity. All rights reserved.
//

import UIKit

class SensorView: UIView {

    var sensorName: String = "Name: -" {
        didSet {
            sensorNameLabel.text = "Name: \(sensorName)"
        }
    }

    var firmwareVersion: String = "Firmware: -" {
        didSet {
            firmwareVersionLabel.text = "Firmware: \(firmwareVersion)"
        }
    }

    var sensorId: String = "Id: -" {
        didSet {
            sensorIdLabel.text = "Id: \(sensorId)"
        }
    }

    private lazy var nameLabel: UILabel = {
        let label = UILabel()
        label.textColor = .black
        label.textAlignment = .left
        label.font = .boldSystemFont(ofSize: 32)
        label.numberOfLines = 0
        label.translatesAutoresizingMaskIntoConstraints = false
        label.text = "Sensor"
        return label
    }()

    private lazy var sensorNameLabel: UILabel = {
        let label = UILabel()
        label.text = sensorName
        label.textColor = .lightGray
        label.textAlignment = .left
        label.font = .systemFont(ofSize: 18)
        label.numberOfLines = 0
        label.translatesAutoresizingMaskIntoConstraints = false
        return label
    }()

    private lazy var firmwareVersionLabel: UILabel = {
        let label = UILabel()
        label.text = sensorName
        label.textColor = .lightGray
        label.textAlignment = .left
        label.font = .systemFont(ofSize: 18)
        label.numberOfLines = 0
        label.translatesAutoresizingMaskIntoConstraints = false
        return label
    }()

    private lazy var sensorIdLabel: UILabel = {
        let label = UILabel()
        label.text = sensorId
        label.textColor = .lightGray
        label.textAlignment = .left
        label.font = .systemFont(ofSize: 18)
        label.numberOfLines = 0
        label.translatesAutoresizingMaskIntoConstraints = false
        return label
    }()

    init() {
        super.init(frame: .zero)
        translatesAutoresizingMaskIntoConstraints = false
        backgroundColor = .white
        layer.cornerRadius = 10
        clipsToBounds = true
        addSubview(nameLabel)
        var margins = safeAreaLayoutGuide
        nameLabel.topAnchor.constraint(equalTo: margins.topAnchor, constant: 5).isActive = true
        nameLabel.leftAnchor.constraint(equalTo: margins.leftAnchor, constant: 5).isActive = true
        nameLabel.rightAnchor.constraint(equalTo: margins.rightAnchor, constant: -5).isActive = true
        nameLabel.heightAnchor.constraint(equalToConstant: 35).isActive = true
        addSubview(sensorNameLabel)

        margins = nameLabel.safeAreaLayoutGuide
        sensorNameLabel.topAnchor.constraint(equalTo: margins.bottomAnchor, constant: 0).isActive = true
        sensorNameLabel.leftAnchor.constraint(equalTo: margins.leftAnchor, constant: 0).isActive = true
        sensorNameLabel.rightAnchor.constraint(equalTo: margins.rightAnchor, constant: 0).isActive = true
        sensorNameLabel.heightAnchor.constraint(equalToConstant: 25).isActive = true

        margins = sensorNameLabel.safeAreaLayoutGuide
        addSubview(firmwareVersionLabel)
        firmwareVersionLabel.topAnchor.constraint(equalTo: margins.bottomAnchor, constant: 0).isActive = true
        firmwareVersionLabel.leftAnchor.constraint(equalTo: margins.leftAnchor, constant: 0).isActive = true
        firmwareVersionLabel.rightAnchor.constraint(equalTo: margins.rightAnchor, constant: 0).isActive = true
        firmwareVersionLabel.heightAnchor.constraint(equalToConstant: 25).isActive = true

        margins = firmwareVersionLabel.safeAreaLayoutGuide
        addSubview(sensorIdLabel)
        sensorIdLabel.topAnchor.constraint(equalTo: margins.bottomAnchor, constant: 0).isActive = true
        sensorIdLabel.leftAnchor.constraint(equalTo: margins.leftAnchor, constant: 0).isActive = true
        sensorIdLabel.rightAnchor.constraint(equalTo: margins.rightAnchor, constant: 0).isActive = true
        sensorIdLabel.heightAnchor.constraint(equalToConstant: 25).isActive = true
    }

    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}
