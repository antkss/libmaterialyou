pkgname=libmaterialyou
pkgver=1
pkgrel=1
pkgdesc="for c++ "
arch=(x86_64)
license=(BSD)


options=(!docs !debug !strip)

prepare() {
    echo lmao
}

build() {
    cd $srcdir/..
    make
}

package() {
    cd $srcdir/..
    mkdir -p $pkgdir/usr/lib
    mkdir -p $pkgdir/usr/include/material
    cp ./libmaterialyou.so $pkgdir/usr/lib
    cp src/*.h $pkgdir/usr/include/material
}
