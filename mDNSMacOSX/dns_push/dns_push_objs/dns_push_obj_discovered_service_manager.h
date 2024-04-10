/*
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
 */

#ifndef DNS_PUSH_OBJ_DISCOVERED_SERVICE_MANAGER_H
#define DNS_PUSH_OBJ_DISCOVERED_SERVICE_MANAGER_H

#include "mDNSFeatures.h"
#if MDNSRESPONDER_SUPPORTS(APPLE, DNS_PUSH)

//======================================================================================================================
// MARK: - Headers

#include "dns_obj_domain_name.h"
#include "dns_push_obj.h"
#include "general.h"

//======================================================================================================================
// MARK: - Object Reference Definition

DNS_PUSH_OBJECT_TYPEDEF_OPAQUE_POINTER(discovered_service_manager);

//======================================================================================================================
// MARK: - Object Methods

NULLABILITY_ASSUME_NONNULL_BEGIN

__BEGIN_DECLS

dns_push_obj_discovered_service_manager_t NULLABLE
dns_push_obj_discovered_service_manager_create(dns_obj_domain_name_t discovered_authoritative_zone, uint32_t if_index,
	dns_obj_error_t * NULLABLE out_error);

bool
dns_push_obj_discovered_service_manager_manages_this_zone(dns_push_obj_discovered_service_manager_t manager,
	dns_obj_domain_name_t discovered_authoritative_zone, uint32_t if_index);

__END_DECLS

NULLABILITY_ASSUME_NONNULL_END

#endif // MDNSRESPONDER_SUPPORTS(APPLE, DNS_PUSH)

#endif // DNS_PUSH_OBJ_DISCOVERED_SERVICE_MANAGER_H
