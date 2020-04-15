//
//  EventLogView.swift
//  PlayfinityKitExample
//
//  Created by playfinity on 14/04/2020.
//  Copyright © 2020 io.playfinity. All rights reserved.
//

import UIKit

struct EventLog {
    let title: String
    let bottomText: String
}

class EventLogView: UIView {

    private var datasource: [EventLog] = []

    private lazy var nameLabel: UILabel = {
        let label = UILabel()
        label.textColor = .black
        label.textAlignment = .left
        label.font = .boldSystemFont(ofSize: 32)
        label.numberOfLines = 0
        label.translatesAutoresizingMaskIntoConstraints = false
        label.text = "Event's log:"
        return label
    }()

    private lazy var tblView: UITableView = {
        let view = UITableView.init()
        view.translatesAutoresizingMaskIntoConstraints = false
        view.dataSource = self
        return view
    }()

    init() {
        super.init(frame: .zero)
        translatesAutoresizingMaskIntoConstraints = false
        backgroundColor = .white
        layer.cornerRadius = 10
        layer.maskedCorners = [.layerMaxXMinYCorner, .layerMinXMinYCorner]
        clipsToBounds = true

        addSubview(nameLabel)
        var margins = safeAreaLayoutGuide
        nameLabel.topAnchor.constraint(equalTo: margins.topAnchor, constant: 5).isActive = true
        nameLabel.leftAnchor.constraint(equalTo: margins.leftAnchor, constant: 5).isActive = true
        nameLabel.rightAnchor.constraint(equalTo: margins.rightAnchor, constant: -5).isActive = true

        addSubview(tblView)
        margins = nameLabel.safeAreaLayoutGuide
        tblView.topAnchor.constraint(equalTo: margins.bottomAnchor, constant: 5).isActive = true
        tblView.leftAnchor.constraint(equalTo: safeAreaLayoutGuide.leftAnchor, constant: 0).isActive = true
        tblView.rightAnchor.constraint(equalTo: safeAreaLayoutGuide.rightAnchor, constant: 0).isActive = true
        tblView.bottomAnchor.constraint(equalTo: safeAreaLayoutGuide.bottomAnchor, constant: 0).isActive = true
        tblView.tableFooterView = UIView()
    }

    func add(eventLog: EventLog) {
        datasource.append(eventLog)
        tblView.reloadData()
    }

    func clear() {
        datasource.removeAll()
        tblView.reloadData()
    }

    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}


extension EventLogView: UITableViewDataSource {
    func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }

    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return datasource.count
    }

    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let log = datasource[indexPath.row]

        if let cell = tableView.dequeueReusableCell(withIdentifier: "defaultCell") {
            cell.textLabel?.text = log.title
            cell.detailTextLabel?.text = log.bottomText
            return cell
        } else {
            let newCell = UITableViewCell.init(style: .subtitle, reuseIdentifier: "defaultCell")
            newCell.textLabel?.text = log.title
            newCell.detailTextLabel?.text = log.bottomText
            return newCell

        }
    }
}
