# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kyototycoon
PORTVERSION=	0.9.56
PORTREVISION=	6
CATEGORIES=	databases
MASTER_SITES=	https://dbmx.net/kyototycoon/pkg/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Handy cache/storage server

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libkyotocabinet.so:databases/kyotocabinet

OPTIONS_DEFINE=	DOCS LZO

CONFIGURE_ARGS=	--enable-uyield
CPPFLAGS+=	-fPIC
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
MAKE_ARGS=	PCDIR=${PREFIX}/libdata/pkgconfig
REINPLACE_ARGS=	-i ''
TEST_TARGET=	check
USE_CXXSTD=	gnu++98
USE_LDCONFIG=	yes
USE_RC_SUBR=	${PORTNAME}
USES=		gmake pkgconfig

PLIST_SUB=	KYOTOTYCOON_USER=${KYOTOTYCOON_USER} \
		KYOTOTYCOON_GROUP=${KYOTOTYCOON_GROUP} \
		KYOTOTYCOON_DBDIR=${KYOTOTYCOON_DBDIR} \
		KYOTOTYCOON_LOGDIR=${KYOTOTYCOON_LOGDIR} \
		KYOTOTYCOON_PIDFILE=${KYOTOTYCOON_PIDFILE}
PORTDOCS=	*
SUB_FILES=	${PORTNAME}
SUB_LIST=	KYOTOTYCOON_USER=${KYOTOTYCOON_USER} \
		KYOTOTYCOON_GROUP=${KYOTOTYCOON_GROUP} \
		KYOTOTYCOON_DBDIR=${KYOTOTYCOON_DBDIR} \
		KYOTOTYCOON_LOGDIR=${KYOTOTYCOON_LOGDIR} \
		KYOTOTYCOON_PIDFILE=${KYOTOTYCOON_PIDFILE}

USERS=		${KYOTOTYCOON_USER}
GROUPS=		${KYOTOTYCOON_GROUP}

KYOTOTYCOON_USER?=	${PORTNAME}
KYOTOTYCOON_GROUP?=	${PORTNAME}
KYOTOTYCOON_DBDIR?=	/var/db/${PORTNAME}
KYOTOTYCOON_LOGDIR?=	/var/log/${PORTNAME}
KYOTOTYCOON_PIDFILE?=	/var/run/${PORTNAME}.pid

LZO_CONFIGURE_OFF=	ac_cv_lib_lzo2_main=no
LZO_CONFIGURE_ON=	ac_cv_lib_lzo2_main=yes
LZO_LIB_DEPENDS=	liblzo2.so:archivers/lzo2

post-patch:
	@${REINPLACE_CMD} -e 's|-lstdc++ ||g' ${WRKSRC}/configure ${WRKSRC}/doc/spex.html ${WRKSRC}/example/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libkyototycoon.so.2.19.0 ${STAGEDIR}${PREFIX}/libexec/*.so

post-install-DOCS-on:
	${FIND} ${STAGEDIR}${DOCSDIR}/ -type d -exec ${CHMOD} ${BINMODE} {} +
	${FIND} ${STAGEDIR}${DOCSDIR}/ -type f -exec ${CHMOD} ${DOCMODE} {} +

.include <bsd.port.mk>
