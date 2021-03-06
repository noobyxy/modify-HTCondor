/***************************************************************
 *
 * Copyright (C) 1990-2007, Condor Team, Computer Sciences Department,
 * University of Wisconsin-Madison, WI.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License"); you
 * may not use this file except in compliance with the License.  You may
 * obtain a copy of the License at
 * 
 *    http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ***************************************************************/

#include "condor_common.h"
#include "condor_debug.h"
#include "hwcloudgahp_common.h"
#include "request.h"

Request::Request (const char *cmd)
{   
	m_worker = NULL;
	m_raw_cmd = cmd;

	if ( parse_gahp_command(cmd, &m_args) )
		m_reqid = (int)strtol(m_args.argv[1], (char **)NULL, 10);
	else
		m_reqid = -1;
}
