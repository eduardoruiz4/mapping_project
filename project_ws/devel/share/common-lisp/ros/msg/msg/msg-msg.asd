
(cl:in-package :asdf)

(defsystem "msg-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "my_pose" :depends-on ("_package_my_pose"))
    (:file "_package_my_pose" :depends-on ("_package"))
  ))