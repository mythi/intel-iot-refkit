# Include security flags pulled in via openembedded-core.
require conf/distro/include/security_flags.inc

SECURITY_PIC_CFLAGS ?= "-fpic"

# Add IoT Reference OS Kit specific flags to fix build issues with
# recipes that are being used in IoT Reference OS Kit.
SECURITY_CFLAGS_pn-efivar = "${SECURITY_NO_PIE_CFLAGS} ${SECURITY_PIC_CFLAGS}"
SECURITY_CFLAGS_pn-zeromq = "${SECURITY_NO_PIE_CFLAGS} ${SECURITY_PIC_CFLAGS}"
SECURITY_CFLAGS_pn-mraa = "${SECURITY_NO_PIE_CFLAGS} ${SECURITY_PIC_CFLAGS}"
SECURITY_CFLAGS_pn-upm = "${SECURITY_NO_PIE_CFLAGS} ${SECURITY_PIC_CFLAGS}"
# -D_FORTIFY_SOURCE=2 causes compilation of oc_logger/examples/c_test_logging.o
# to fail because -O is not passed to that one.
# |  #  warning _FORTIFY_SOURCE requires compiling with optimization (-O)
# cc1: all warnings being treated as errors
SECURITY_CFLAGS_pn-iotivity = "${@ '${SECURITY_NO_PIE_CFLAGS} ${SECURITY_PIC_CFLAGS}'.replace('-D_FORTIFY_SOURCE=2', '') }"
SECURITY_CFLAGS_pn-krb5 = "${SECURITY_NO_PIE_CFLAGS} ${SECURITY_PIC_CFLAGS}"
SECURITY_CFLAGS_pn-tbb = "${SECURITY_NO_PIE_CFLAGS} ${SECURITY_PIC_CFLAGS}"
SECURITY_CFLAGS_pn-protobuf = "${SECURITY_NO_PIE_CFLAGS} ${SECURITY_PIC_CFLAGS}"
SECURITY_CFLAGS_pn-glog = "${SECURITY_NO_PIE_CFLAGS} ${SECURITY_PIC_CFLAGS}"
SECURITY_CFLAGS_pn-clang = "${SECURITY_NO_PIE_CFLAGS} ${SECURITY_PIC_CFLAGS}"
SECURITY_CFLAGS_pn-log4cxx = "${SECURITY_NO_PIE_CFLAGS} ${SECURITY_PIC_CFLAGS}"
SECURITY_CFLAGS_pn-python3-lxml = "${SECURITY_NO_PIE_CFLAGS} ${SECURITY_PIC_CFLAGS}"
SECURITY_CFLAGS_pn-python3-netifaces = "${SECURITY_NO_PIE_CFLAGS} ${SECURITY_PIC_CFLAGS}"
SECURITY_CFLAGS_pn-python3-pyyaml = "${SECURITY_NO_PIE_CFLAGS} ${SECURITY_PIC_CFLAGS}"
SECURITY_CFLAGS_pn-moveit-ros-perception = "${SECURITY_NO_PIE_CFLAGS} ${SECURITY_PIC_CFLAGS}"

# openjdk-8 ends up linking with "-shared -pie -fpie" in some cases (see
# hotspot/make/linux/makefiles/saproc.make) which then tries (and fails) to
# produce an executable instead of a shared object because main() is
# undefined.
SECURITY_CFLAGS_pn-openjdk-8 = "${SECURITY_NO_PIE_CFLAGS}"
SECURITY_CFLAGS_pn-openjre-8 = "${SECURITY_NO_PIE_CFLAGS}"

# Additional exceptions for packages in IoT Reference OS Kit which do not
# compile with -Wformat-security as error (sorted alphabetically).
SECURITY_STRINGFORMAT_pn-dash = ""
SECURITY_STRINGFORMAT_pn-giflib = ""
SECURITY_STRINGFORMAT_pn-gsignond = ""
SECURITY_STRINGFORMAT_pn-openjdk-8 = ""
SECURITY_STRINGFORMAT_pn-openjre-8 = ""
SECURITY_STRINGFORMAT_pn-qhull = ""
