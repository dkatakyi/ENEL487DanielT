#!/usr/bin/env python2
# This python script  exercises the complex addition, subtraction,
# multiplication, and division operations for the complex calculator.
# I've attempted to use representative numbers in the range (-.5,+.5),
# (-.5e9, +.5e9), (-.5e-9, +.5e-9), and every combination involving 0.
# Note that this test program does NOT exercise the error detection
# requirement.

import subprocess
import sys

# Here's the program name:
if len(sys.argv) != 2:
    print "Usage: runtests.py prog_to_test"
    sys.exit(1)

prog = sys.argv[1]  # set the program to test

# Here is the structure of the test tuples:
# ( cmd_string, expected_result_string )
testvectors = (
    ("a 4 5 6 7", "10 + j 12"),
    ("s 4 5 6 7", "-2 - j 2"),
    ("m 4 5 6 7", "-11 + j 58"),
    ("d 4 5 6 7", "0.694118 + j 0.0235294"),
    
    ("A -0.47418861463666 0.36706668138504 -0.432650379836559 " +
     "0.229521870613098",
     "-0.906839 + j 0.596589"),

    ("S 0.425315856933594 0.477817177772522 0.174881994724274 " +
     "0.0820413827896118",
     "0.250434 + j 0.395776"),

    ("M 0.133698165416718 0.155414998531342 0.00195854902267456 " +
     "-0.498182915151119",
    "0.077687 - j 0.0663018"),

    ("D 0.397469758987427 -0.490663632750511 0.0430329442024231 " +
     "0.355984449386597",
    "-1.22545 - j 1.26467"),


    ("A -0.47 0.37 -0.43 0.23",
     "-0.9 + j 0.6"),
    ("S 0.43 0.48 0.17 0.08",
     "0.26 + j 0.4"),
    ("M 0.13 0.16 0.00 -0.50",
     "0.08 - j 0.065"),
    ("D 0.40 -0.49 0.04 0.36",
     "-1.22256 - j 1.24695"),
    ("M -0.7071 0.7071 0.7071 0.7071",
     "-0.999981 + j 0"),
    ("D -0.7071 .7071 .7071 .7071",
     "0 + j 1"),

    ("A -13000000 -370000000 420000000 340000000",
     "4.07e+08 - j 3e+07"),
    ("S -230000000 440000000 400000000 120000000",
     "-6.3e+08 + j 3.2e+08"),
    ("M -400000000 410000000 -180000000 -160000000",
     "1.376e+17 - j 9.8e+15"),
    ("D 360000000 -410000000 330000000 -390000000",
     "1.06782 + j 0.0195402"),

    ("A 5.9e-11 -2.6e-10 3.4e-10 -2.5e-10",
     "3.99e-10 - j 5.1e-10"),
    ("S 1.1e-10 -1.5e-10 5.9e-11 -3.4e-10",
     "5.1e-11 + j 1.9e-10"),
    ("M 4.2e-10 2.5e-10 3.1e-10 -4.5e-10",
     "2.427e-19 - j 1.115e-19"),
    ("D 3.2e-10 3.7e-10 7.1e-11 -2.0e-10",
     "-1.13852 + j 2.00417"),

    ("A 0.31 -0.15 0 0",
     "0.31 - j 0.15"),
    ("S 0.46 -0.15 0 0",
     "0.46 - j 0.15"),
    ("M -0.22 0.23 0 0",
     "-0 + j 0"),

    ("A 0 0 0.27 -0.24",
     "0.27 - j 0.24"),
    ("S 0 0 -0.28 -0.42",
     "0.28 + j 0.42"),
    ("M 0 0 0.07 0.17",
     "0 + j 0"),
    ("D 0 0 0.47 -0.15",
     "0 + j 0"),


    ("A -13263046.7414856 -365942224.860191 417038738.72757 336516857.147217",
    "4.03776e+08 - j 2.94254e+07"),

    ("S -228525519.371033 435311019.420624 403060495.853424 122398972.511292",
    "-6.31586e+08 + j 3.12912e+08"),

    ("M -399775691.330433 406372129.917145 -182631433.010101 " +
     "-157639920.711517",
    "1.37072e+17 - j 1.11957e+16"),

    ("D 362544298.171997 -405336491.763592 327183306.217194 -389134742.319584",
    "1.06915 + j 0.0327276"),


    ("A 5.88880181312561e-11 -2.57283389568329e-10 3.37269246578217e-10 " +
     "-2.54886001348495e-10",
     "3.96157e-10 - j 5.12169e-10"),

    ("S 1.11319720745087e-10 -1.4580026268959e-10 5.86002469062805e-11 " +
     "-3.36027354001999e-10",
     "5.27195e-11 + j 1.90227e-10"),

    ("M 4.19571816921234e-10 2.51936137676239e-10 3.14362645149231e-10 " +
     "-4.5363487303257e-10",
     "2.46185e-19 - j 1.11133e-19"),

    ("D 3.19565117359161e-10 3.67686033248901e-10 7.12081789970398e-11 " +
     "-1.9762659072876e-10",
     "-1.13103 + j 2.02454"),


    ("A 0.31309312582016 -0.152247250080109 0 0",
     "0.313093 - j 0.152247"),


    ("S 0.463042140007019 -0.1508948802948 0 0",
     "0.463042 - j 0.150895"),

    ("M -0.224667966365814 0.234481692314148 0 0",
     "-0 + j 0"),



    ("A 0 0 0.270942628383636 -0.244427978992462",
     "0.270943 - j 0.244428"),

    ("S 0 0 -0.284938558936119 -0.424666717648506",
     "0.284939 + j 0.424667"),

    ("M 0 0 0.07303386926651 0.169630944728851",
     "0 + j 0"),


    ("D 0 0 0.466610074043274 -0.148408263921738",
     "0 + j 0"),

    ("d 4 0 2 0",
     "2 + j 0"),

    ("d 0 4 0 2",
     "2 + j 0"),

    ("A 0 0 0 0",
     "0 + j 0"),

    ("S 0 0 0 0",
     "0 + j 0"),

    ("M 0 0 0 0",
     "0 + j 0"),
    
    # Divide by zero is likely to cause errors, as I didn't specify behaviour.
    # Comment out these lines if that's a problem
    # ("D 0.43 0.34 0 0",
    #  "nan + j nan"),
    # ("D 0.430895388126373 0.339199960231781 0 0",
    #  "nan + j nan"),
    # ("D 0 0 0 0",
    #  "nan + j nan"),

)


def is_equal(actual, expected):
    TOL = 1e-5

    # check for NaNs
    if actual.find("nan") >= 0:
        if expected.find("nan") >= 0:
            return True
        else:
            return False

    def convert_to_complex(result_string):
        (re, plusminus, jay, im) = result_string.split()
        if plusminus == "+": sign = 1
        else: sign = -1
        complex_result = complex(float(re), sign*float(im))
        return complex_result
        
    actual = convert_to_complex(actual)
    expected = convert_to_complex(expected)

    if abs(expected) > TOL:
        error = (actual-expected) / expected
    else:
        error = (actual-expected)
    if abs( error ) < TOL:
        return True

    return False

def connect_to_prog(prog):
    pipe = subprocess.Popen(prog, stdin=subprocess.PIPE,
                            stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    return pipe

for vec in testvectors:
    pipe = connect_to_prog(prog)
    (actual_output, eee) = pipe.communicate(vec[0] + "\nq\n")
    #print actual_output
    expected_output = vec[1]
    
    try:
        if is_equal(actual_output, expected_output):
            print ".",
        else:
            print "Tolerance ERROR: "
            print "input: ", vec[0]
            print "expected result: ", vec[1]
            print "actual result: ", actual_output
            #sys.exit(2)
    except:
        print "ERROR: "
        print "input: ", vec[0]
        print "expected result: ", vec[1]
        print "actual result: ", actual_output
        #sys.exit(2)

print "OK"
