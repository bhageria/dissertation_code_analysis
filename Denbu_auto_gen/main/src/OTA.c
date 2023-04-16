#include "esp_https_ota.h"
#include "src/OTA.h"

void OTA_Update()
{
    esp_http_client_config_t ota_client_config = {
        .url = URL,
        //.cert_pem = server_cert_pem_start,
    };
    esp_err_t ret = esp_https_ota(&ota_client_config);
    if (ret == ESP_OK) {
        printf("OTA OK, restarting...\n");
        esp_restart();
    } else {
        printf("OTA failed...\n");
        }
}