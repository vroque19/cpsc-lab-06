#!/usr/bin/env python3
#
# Copyright 2021 Michael Shafae
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
# 
# 1. Redistributions of source code must retain the above copyright notice,
#    this list of conditions and the following disclaimer.
# 
# 2. Redistributions in binary form must reproduce the above copyright notice,
#    this list of conditions and the following disclaimer in the documentation
#    and/or other materials provided with the distribution.
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
""" Check student's submission; requires the main file and the
    template file from the original repository. """
# pexpect documentation
#  https://pexpect.readthedocs.io/en/stable/index.html
import io
import logging
import pexpect
from srcutilities import solution_check_make

# to run locally 
# PYTHONPATH=../.action python3 solution_check_datediff.py  . is_it_prime

def has_isqrt_function(file):
    """ Check if a given file has a C++ main function. """
    status = False
    # int GregorianToJulian(int day, int month, int year) {
    regex = re.compile(r'int\s*IntegerSquareRoot\s*\(\s*int\s*number\s*\)')
    with open(file, 'r') as file_handle:
        src_code = file_handle.read()
        matches = regex.search(src_code)
        if matches:
            status = True
    return status

def run(binary):
    status = True
    values = (
       (0, 'not'),
       (1, 'not'),
       (2, ''),
       (2791, ''),
       (4099, ''),
       (1901, ''),
       (361201, 'not'),
       (7901, ''),
       (62425801, 'not'),
       (2147483647, ''),
       (-12, 'not'),
       (-23, 'not'),
       (10, 'not'),
       (9, 'not'),
       (16, 'not'),
       (2842, 'not'),
       (2836, 'not'),
       (-62425801, 'not'),
       (-2147483647, 'not'),
        )
    for index, val in enumerate(values):
        logging.info('Test %d - %s', index + 1, val)
        _status = _run(binary, val)
        status = status and _status
        #if not status:
        #    logging.error("Did not receive expected response. Halting test.")
        #    break
    return status


def _run(binary, values):
    """ This is the test for the BMR program given the inputs from run_p1 """
    status = False
    values = list(map(str, values))
    cmd = binary + " {}".format(values[0])
    proc = pexpect.spawn(cmd, timeout=1)
    #proc.logfile = sys.stdout.buffer
    out = io.BytesIO()
    proc.logfile = out

    expect_list = [
        r'(?i)\s*{}\s*is\s*{}\s*prime'.format(values[0], values[1]),
        pexpect.EOF,
    ]

    expect_match = proc.expect(expect_list)
    if expect_match < (len(expect_list) - 1):
        logging.info(out.getvalue().decode("utf-8").rstrip('\r\n'))
        status = True
    else:
        logging.error('---- Failed ----')
        logging.error('Matched %s', proc.match)
        logging.error('Expected: "%s is %s prime"', values[0], values[1])
        logging.error('Received (last 100 chars):')
        logging.error(proc.before.decode('utf-8').rstrip('\r\n'))
        status = False
    proc.close()
    #if proc.exitstatus == 0:
    #    status = True
    return status


if __name__ == '__main__':
    solution_check_make(run=run)
