//
//  CounterView.swift
//  PlayfinityKitExample
//
//  Created by playfinity on 14/04/2020.
//  Copyright © 2020 io.playfinity. All rights reserved.
//

import UIKit

class CounterView: UIView {

    var eventName: String = "-" {
        didSet {
            counterLabel.text = "Counter: \(counter) \(eventName)"
        }
    }

    var counter: Int = 0 {
        didSet {
            counterLabel.text = "Counter: \(counter) \(eventName)"
        }
    }

    private lazy var counterLabel: UILabel = {
        let label = UILabel()
        label.textColor = .black
        label.textAlignment = .left
        label.font = .boldSystemFont(ofSize: 32)
        label.numberOfLines = 0
        label.translatesAutoresizingMaskIntoConstraints = false
        label.text = "Counter: \(counter) \(eventName)"
        return label
    }()

    init() {
        super.init(frame: .zero)
        translatesAutoresizingMaskIntoConstraints = false
        backgroundColor = .white
        layer.cornerRadius = 10
        clipsToBounds = true
        addSubview(counterLabel)
        let margins = safeAreaLayoutGuide
        counterLabel.topAnchor.constraint(equalTo: margins.topAnchor, constant: 5).isActive = true
        counterLabel.leftAnchor.constraint(equalTo: margins.leftAnchor, constant: 5).isActive = true
        counterLabel.rightAnchor.constraint(equalTo: margins.rightAnchor, constant: -5).isActive = true
        counterLabel.bottomAnchor.constraint(equalTo: margins.bottomAnchor, constant: -5).isActive = true
    }

    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }

}
