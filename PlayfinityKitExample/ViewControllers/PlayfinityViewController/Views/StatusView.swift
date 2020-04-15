//
//  StatusView.swift
//  PlayfinityKitExample
//
//  Created by playfinity on 14/04/2020.
//  Copyright © 2020 io.playfinity. All rights reserved.
//

import UIKit

class StatusView: UIView {

    var statusText: String = "STATUS: CONNECTING" {
        didSet {
            statusLabel.text = statusText
        }
    }

    private lazy var nameLabel: UILabel = {
        let label = UILabel()
        label.textColor = .black
        label.textAlignment = .left
        label.font = .boldSystemFont(ofSize: 32)
        label.numberOfLines = 0
        label.translatesAutoresizingMaskIntoConstraints = false
        label.text = "PLAYFINITY SDK"
        return label
    }()

    private lazy var statusLabel: UILabel = {
        let label = UILabel()
        label.text = statusText
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

        addSubview(statusLabel)
        margins = nameLabel.safeAreaLayoutGuide
        statusLabel.topAnchor.constraint(equalTo: margins.bottomAnchor, constant: 3).isActive = true
        statusLabel.leftAnchor.constraint(equalTo: margins.leftAnchor, constant: 0).isActive = true
        statusLabel.rightAnchor.constraint(equalTo: margins.rightAnchor, constant: 0).isActive = true
        statusLabel.heightAnchor.constraint(equalToConstant: 35).isActive = true
    }

    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }



}
