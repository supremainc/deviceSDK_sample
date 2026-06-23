# Fingerprint API

API that provides functions to scan, extract, and compare fingerprint template data.

- [BS2_ScanFingerprint](bs2_scanfingerprint): Scans a fingerprint from a device and extracts template data.

- [BS2_ScanFingerprintEx](bs2_scanfingerprintex):​ Scans a fingerprint from a device and extracts template data and scan image scores.

- [BS2_VerifyFingerprint](bs2_verifyfingerprint): Compares the template data to check if it is the same finger.

- [BS2_GetLastFingerprintImage](bs2_getlastfingerprintimage): Extracts the image of the last scanned fingerprint using the BS2_ScanFingerprint API.

- [BS2_GetFingerTemplateQuality](bs2_getfingertemplatequality): Checks the quality score of the fingerprint from the fingerprint template data.

## Structure

### BS2Fingerprint

```cpp
typedef struct {
    uint8_t index;
    uint8_t flag;
    uint8_t reserved[2];
    uint8_t data[BS2_TEMPLATE_PER_FINGER][BS2_FINGER_TEMPLATE_SIZE];
} BS2Fingerprint;
```

1. `index`

   The index of finger. This is a flag that user can manage manually, not changing automatically. If you want to manage fingerprint index, please assign a number when you enroll fingerprint.

1. `flag`

   Flag that indicates the purpose of the fingerprint.

   | Value | Description |
   | --- | --- |
   | 0 | Normal fingerprint |
   | 1 | Duress fingerprint |

1. `reserved`

   Reserved space.

1. `data`

   The data of fingerprint template.