#!/bin/bash

TEMP_DIR=temp

echo "Starting deb package build"

echo "Making temporary directory tree"

rm -rf $TEMP_DIR
mkdir -p $TEMP_DIR
mkdir -p $TEMP_DIR/usr/local/bin/
mkdir -p $TEMP_DIR/etc/systemd/system/
mkdir -p $TEMP_DIR/DEBIAN

echo "Copy executable to DEBIAN/"
cp linked_list_app $TEMP_DIR/usr/local/bin/

echo "Create fake systemd service file"
cat <<EOF > $TEMP_DIR/etc/systemd/system/linked-list.service
[Unit]
Description=Linked List Application Service
After=network.target

[Service]
ExecStart=/usr/local/bin/linked_list_app
Restart=always
User=nobody

[Install]
WantedBy=multi-user.target
EOF

echo "Create control file"
cat <<EOF > $TEMP_DIR/DEBIAN/control
Package: linked-list
Version: 1.0.0
Architecture: amd64
Maintainer: Keyu Chen <kchen2@zagmail.gonzaga.edu>
Description: A simple linked list C++ application packaged as a Debian service
EOF

echo "Set permissions"
chmod 755 $TEMP_DIR/usr/local/bin/linked_list_app
chmod 644 $TEMP_DIR/etc/systemd/system/linked-list.service
chmod 755 $TEMP_DIR/DEBIAN

echo "Creating post-install script..."
cat <<EOF > $TEMP_DIR/DEBIAN/postinst
#!/bin/sh
systemctl daemon-reload
systemctl enable linked-list.service
systemctl start linked-list.service
exit 0
EOF
chmod 755 $TEMP_DIR/DEBIAN/postinst

echo "Creating pre-remove script..."
cat <<EOF > $TEMP_DIR/DEBIAN/prerm
#!/bin/sh
systemctl stop linked-list.service
exit 0
EOF
chmod 755 $TEMP_DIR/DEBIAN/prerm

echo "Creating post-remove script..."
cat <<EOF > $TEMP_DIR/DEBIAN/postrm
#!/bin/sh
systemctl daemon-reload
exit 0
EOF
chmod 755 $TEMP_DIR/DEBIAN/postrm

echo "Building Debian package..."
dpkg-deb --root-owner-group --build $TEMP_DIR

echo "Renaming package"
mv ${TEMP_DIR}.deb linked-list-v1.0.0.deb

echo "✅ Build complete: linked-list-v1.0.0.deb"
