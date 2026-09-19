// 1000eb30 RwCreateDepthCueColor [Global]
// programa: RWL21.DLL

undefined4 RwCreateDepthCueColor(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  longlong lVar3;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
                    /* 0xeb30  573  RwCreateDepthCueColor */
  puVar2 = (undefined4 *)(PTR_DAT_1005b69c + 0x2a8);
  if (*(int *)(PTR_DAT_1005b69c + 0x2a8) == 0) {
    FUN_1000cba0(0x5f);
    return 0;
  }
  lVar3 = __ftol();
  local_c = (undefined4)lVar3;
  lVar3 = __ftol();
  local_8 = (undefined4)lVar3;
  lVar3 = __ftol();
  local_4 = (undefined4)lVar3;
  uVar1 = (*(code *)*puVar2)(&local_c);
  return uVar1;
}


