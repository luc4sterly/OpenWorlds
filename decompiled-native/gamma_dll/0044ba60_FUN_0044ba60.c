// 0044ba60 FUN_0044ba60 [Global]
// program: gamma.dll

undefined4 FUN_0044ba60(undefined4 *param_1,undefined4 *param_2)

{
  SIZE_T cb;
  LPVOID pvVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  iVar2 = -1;
  do {
    iVar3 = iVar2;
    iVar2 = iVar3 + 1;
  } while (*(short *)((int)param_1 + iVar2 * 2) != 0);
  cb = (iVar3 + 2) * 2;
  pvVar1 = CoTaskMemAlloc(cb);
  *param_2 = pvVar1;
  if ((undefined4 *)*param_2 == (undefined4 *)0x0) {
    return 0x8007000e;
  }
  FUN_0044df50((undefined4 *)*param_2,param_1,cb);
  return 0;
}


