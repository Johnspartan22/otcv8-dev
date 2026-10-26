#ifndef CHAOSKEY_H
#define CHAOSKEY_H

// ============================================================================
//  Chaos Reborn client file-encryption secret.
//
//  KEEP THIS FILE PRIVATE. Anyone who has these four numbers can decrypt
//  every file in your client. Do NOT commit it to a public GitHub repository
//  (add src/framework/util/chaoskey.h to .gitignore).
//
//  The same key must be compiled into the exe that runs --encrypt and into
//  every exe you give to players. If you change the key, every file you
//  encrypted with the old key becomes unreadable by the new exe, so you must
//  re-encrypt a fresh copy of your client and ship new exes.
//
//  Generate your own key on Windows (PowerShell), then paste the 4 lines it
//  prints over the 4 lines below:
//
//    $b = New-Object byte[] 16
//    [System.Security.Cryptography.RNGCryptoServiceProvider]::new().GetBytes($b)
//    foreach ($i in 0..3) { $h = ($b[($i*4)..($i*4+3)] | ForEach-Object { $_.ToString('X2') }) -join ''; "#define CHAOS_KEY_$i 0x$h" }
// ============================================================================

#define CHAOS_KEY_0 0x00000000
#define CHAOS_KEY_1 0x00000000
#define CHAOS_KEY_2 0x00000000
#define CHAOS_KEY_3 0x00000000

#if (CHAOS_KEY_0 == 0) && (CHAOS_KEY_1 == 0) && (CHAOS_KEY_2 == 0) && (CHAOS_KEY_3 == 0)
#error "Set your own secret key in src/framework/util/chaoskey.h before building."
#endif

// 4-character tag written at the start of every encrypted file.
// It is not secret. Must be exactly 4 characters and must not be "ENC3".
#define CHAOS_ENC_MAGIC "CRE1"

#endif
