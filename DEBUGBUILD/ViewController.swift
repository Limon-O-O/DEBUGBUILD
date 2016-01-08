//
//  ViewController.swift
//  DEBUGBUILD
//
//  Created by Limon on 16/1/8.
//  Copyright © 2016年 DEBUGBUILD. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()

        if DEBUG_BUILD {
            print("It's Debug build")
        } else {
            print("It's Release build")
        }
    }

}

