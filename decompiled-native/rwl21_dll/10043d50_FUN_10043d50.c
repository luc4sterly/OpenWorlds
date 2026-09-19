// 10043d50 FUN_10043d50 [Global]
// programa: RWL21.DLL

undefined4 FUN_10043d50(char *param_1)

{
  char cVar1;
  uint uVar2;
  
  cVar1 = *param_1;
  if (cVar1 != DAT_1005a078) {
    if (DAT_1005bb4c < 2) {
      uVar2 = *(ushort *)(PTR_DAT_1005b940 + cVar1 * 2) & 0x103;
    }
    else {
      uVar2 = __isctype((int)cVar1,0x103);
    }
    if ((uVar2 == 0) || (param_1[1] != ':')) {
      return 0;
    }
  }
  return 1;
}


