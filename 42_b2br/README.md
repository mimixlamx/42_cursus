*This project has been created as part of the 42 curriculum by <your_login>.*

# Born2beRoot

## Description
Born2beRoot is an introduction to system administration.  
The goal of this project is to set up a secure Linux server from scratch using virtualization, while following strict rules related to security, users, services, and automation.

This project helped me understand how a Linux system works internally and how to properly configure a basic but secure server environment.

---

## Operating System
I chose **Debian** for this project.

Debian is known for its stability and reliability, which makes it a good choice for servers.  
It also has extensive documentation and a large community, which helped a lot during the project.

---

## Virtual Machine
The virtual machine was created using **VirtualBox**, as required by the subject.  
It allows easy management of the VM and works on all major operating systems.

---

## Disk Management & LVM
The disk is partitioned using **LVM with encryption**.

Using LVM makes disk management more flexible and encryption adds an extra layer of security in case the disk is accessed without authorization.

---

## Security

### AppArmor
AppArmor is enabled at startup to restrict what applications are allowed to do on the system.  
It helps reduce the impact of potential security issues.

### Firewall (UFW)
UFW is used to manage firewall rules.
- Only port **4242** is open for SSH
- All other incoming connections are blocked by default

### SSH
SSH is configured securely:
- Runs on port **4242**
- Root login is disabled
- Used for remote administration only

---

## Users & Password Policy
- A regular user (my login) exists in addition to root
- The user belongs to the `sudo` and `user42` groups
- A strong password policy is enforced (expiration, complexity, restrictions)

---

## Sudo
Sudo is configured with strict rules:
- Limited authentication attempts
- Custom error message
- All sudo commands are logged
- Secure paths and TTY mode enabled

This ensures better security and traceability.

---

## Monitoring Script
A bash script (`monitoring.sh`) runs every 10 minutes using `cron` and displays system information with `wall`.

It shows:
- System and kernel information
- CPU, RAM, and disk usage
- CPU load
- Last reboot
- LVM status
- Active TCP connections
- Logged-in users
- Network information
- Number of sudo commands executed

---

## How to run
The monitoring script can be launched manually with: bash
bash monitoring.sh
It is automatically executed using cron.

Resources

Debian documentation

Linux man pages

Born2beRoot subject

AI usage

AI was used only to help understand concepts and commands.
All configurations were done manually and fully understood.

Conclusion

This project helped me better understand Linux system administration, security basics, and automation.
It provided a solid foundation for working with servers in real environments.
