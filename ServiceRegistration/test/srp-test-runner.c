/* srp-test-runner.h
 *
 * Copyright (c) 2023 Apple Inc. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * This file contains the SRP server test runner.
 */

#include "srp.h"
#include <dns_sd.h>
#include "srp-test-runner.h"
#include "srp-api.h"
#include "dns-msg.h"
#include "ioloop.h"
#include "srp-mdns-proxy.h"
#include "test-api.h"
#include "srp-proxy.h"
#include "srp-mdns-proxy.h"
#include "test-dnssd.h"
#include "test.h"

void
srp_test_server_run_test(void *context)
{
    char *test_to_run = context;

    if (test_to_run != NULL) {
        if (!strcmp(test_to_run, "change-text-record")) {
            test_change_text_record_start(NULL);
        } else if (!strcmp(test_to_run, "multi-host-record")) {
            test_multi_host_record_start(NULL);
        } else if (!strcmp(test_to_run, "lease-expiry")) {
            test_lease_expiry_start(NULL);
        } else if (!strcmp(test_to_run, "lease-renewal")) {
            test_lease_renewal_start(NULL);
        } else if (!strcmp(test_to_run, "single-srpl-update")) {
            test_single_srpl_update(NULL);
        } else if (!strcmp(test_to_run, "srpl-two-instances-dup")) {
            test_srpl_host_2i(NULL, DUP_TEST_VARIANT_BOTH);
        } else if (!strcmp(test_to_run, "srpl-two-instances-dup-first")) {
            test_srpl_host_2i(NULL, DUP_TEST_VARIANT_FIRST);
        } else if (!strcmp(test_to_run, "srpl-two-instances-dup-last")) {
            test_srpl_host_2i(NULL, DUP_TEST_VARIANT_LAST);
        } else if (!strcmp(test_to_run, "srpl-two-instances-dup-add-first")) {
            test_srpl_host_2i(NULL, DUP_TEST_VARIANT_FIRST);
        } else if (!strcmp(test_to_run, "srpl-two-instances-dup-add-last")) {
            test_srpl_host_2i(NULL, DUP_TEST_VARIANT_LAST);
        } else if (!strcmp(test_to_run, "srpl-two-instances-dup-2keys")) {
            test_srpl_host_2i(NULL, DUP_TEST_VARIANT_TWO_KEYS);
        } else if (!strcmp(test_to_run, "srpl-two-instances")) {
            test_srpl_host_2i(NULL, DUP_TEST_VARIANT_NO_DUP);
        } else if (!strcmp(test_to_run, "srpl-two-instances-one-remove")) {
            test_srpl_host_2ir(NULL);
        } else if (!strcmp(test_to_run, "srpl-zero-instances-two-servers")) {
            test_srpl_host_0i2s(NULL);
        } else {
            INFO("test to run: %s", test_to_run);
            exit(1);
        }
    } else {
        INFO("no test to run");
        exit(1);
    }
}

void *
srp_test_server_find_instance(void *state, const char *name, const char *regtype)
{
    test_state_t *test_state = (test_state_t *)state;
    srp_server_t *server = test_state->primary;
    adv_host_t *host;
    adv_instance_t *instance;

    for (host = server->hosts; host != NULL; host = host->next) {
        if (host->instances != NULL) {
            for (int i = 0; i < host->instances->num; i++) {
                if (host->instances->vec[i] != NULL) {
                    instance = host->instances->vec[i];
                    if (!strcmp(instance->instance_name, name) &&
                        !strcmp(instance->service_type, regtype))
                    {
                        return instance;
                    }
                }
            }
        }
    }
    return NULL;
}

// Local Variables:
// mode: C
// tab-width: 4
// c-file-style: "bsd"
// c-basic-offset: 4
// fill-column: 108
// indent-tabs-mode: nil
// End:
