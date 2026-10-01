// 100047d0 RwGetClumpLTM [Global]
// program: RWL21.DLL

longlong __thiscall RwGetClumpLTM(void *this,undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  void *extraout_ECX;
  undefined4 *puVar2;
  undefined4 extraout_EDX;
  undefined4 uVar3;
  uint extraout_EDX_00;
  longlong lVar4;
  
                    /* 0x47d0  154  RwGetClumpLTM */
  puVar2 = (undefined4 *)0x0;
  if ((param_1 != (undefined4 *)0x0) && (param_2 != (undefined4 *)0x0)) {
    if (param_1 != (undefined4 *)0x0) {
      this = (void *)0x0;
      puVar1 = param_1;
      do {
        if ((*(char *)((int)puVar1 + 0x12d) != '\0') || (*(char *)((int)puVar1 + 0x171) != '\0')) {
          puVar2 = puVar1;
        }
        puVar1 = (undefined4 *)puVar1[0x5d];
      } while (puVar1 != (undefined4 *)0x0);
    }
    uVar3 = 0;
    if (puVar2 != (undefined4 *)0x0) {
      FUN_10004700(this,puVar2,(float *)puVar2);
      this = extraout_ECX;
      uVar3 = extraout_EDX;
    }
    lVar4 = FUN_100510e0(this,uVar3,param_1,param_2);
    return lVar4;
  }
  FUN_1000cba0(1);
  return (ulonglong)extraout_EDX_00 << 0x20;
}


