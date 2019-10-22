#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_status.h"
#include "../model/v1beta1_certificate_signing_request.h"
#include "../model/v1beta1_certificate_signing_request_list.h"


// create a CertificateSigningRequest
//
v1beta1_certificate_signing_request_t*
CertificatesV1beta1API_createCertificatesV1beta1CertificateSigningRequest(apiClient_t *apiClient ,v1beta1_certificate_signing_request_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// delete a CertificateSigningRequest
//
v1_status_t*
CertificatesV1beta1API_deleteCertificatesV1beta1CertificateSigningRequest(apiClient_t *apiClient ,char * name ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body);


// delete collection of CertificateSigningRequest
//
v1_status_t*
CertificatesV1beta1API_deleteCertificatesV1beta1CollectionCertificateSigningRequest(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body);


// get available resources
//
v1_api_resource_list_t*
CertificatesV1beta1API_getCertificatesV1beta1APIResources(apiClient_t *apiClient);


// list or watch objects of kind CertificateSigningRequest
//
v1beta1_certificate_signing_request_list_t*
CertificatesV1beta1API_listCertificatesV1beta1CertificateSigningRequest(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// partially update the specified CertificateSigningRequest
//
v1beta1_certificate_signing_request_t*
CertificatesV1beta1API_patchCertificatesV1beta1CertificateSigningRequest(apiClient_t *apiClient ,char * name , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// partially update status of the specified CertificateSigningRequest
//
v1beta1_certificate_signing_request_t*
CertificatesV1beta1API_patchCertificatesV1beta1CertificateSigningRequestStatus(apiClient_t *apiClient ,char * name , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force);


// read the specified CertificateSigningRequest
//
v1beta1_certificate_signing_request_t*
CertificatesV1beta1API_readCertificatesV1beta1CertificateSigningRequest(apiClient_t *apiClient ,char * name ,char * pretty ,int exact ,int export);


// read status of the specified CertificateSigningRequest
//
v1beta1_certificate_signing_request_t*
CertificatesV1beta1API_readCertificatesV1beta1CertificateSigningRequestStatus(apiClient_t *apiClient ,char * name ,char * pretty);


// replace the specified CertificateSigningRequest
//
v1beta1_certificate_signing_request_t*
CertificatesV1beta1API_replaceCertificatesV1beta1CertificateSigningRequest(apiClient_t *apiClient ,char * name ,v1beta1_certificate_signing_request_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


// replace approval of the specified CertificateSigningRequest
//
v1beta1_certificate_signing_request_t*
CertificatesV1beta1API_replaceCertificatesV1beta1CertificateSigningRequestApproval(apiClient_t *apiClient ,char * name ,v1beta1_certificate_signing_request_t * body ,char * dryRun ,char * fieldManager ,char * pretty);


// replace status of the specified CertificateSigningRequest
//
v1beta1_certificate_signing_request_t*
CertificatesV1beta1API_replaceCertificatesV1beta1CertificateSigningRequestStatus(apiClient_t *apiClient ,char * name ,v1beta1_certificate_signing_request_t * body ,char * pretty ,char * dryRun ,char * fieldManager);


