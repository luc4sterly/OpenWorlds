// 10060a40 FUN_10060a40 [Global]
// program: RWDL8D21.DLL

void __cdecl FUN_10060a40(int param_1)

{
  if ((param_1 != 0) && (*(undefined **)(param_1 + 0xc) != &DAT_100776dc)) {
    _free(*(undefined **)(param_1 + 0xc));
    _free(*(void **)(param_1 + 0x10));
    _free(*(void **)(param_1 + 0x14));
    _free(*(void **)(param_1 + 0x18));
    _free(*(void **)(param_1 + 0x1c));
    _free(*(void **)(param_1 + 0x20));
    _free(*(void **)(param_1 + 0x24));
  }
  return;
}


