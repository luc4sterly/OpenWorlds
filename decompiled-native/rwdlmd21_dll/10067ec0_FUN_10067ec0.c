// 10067ec0 FUN_10067ec0 [Global]
// programa: rwdlmd21.dll

void __cdecl FUN_10067ec0(int param_1)

{
  if ((param_1 != 0) && (*(undefined **)(param_1 + 0xc) != &DAT_1008970c)) {
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


