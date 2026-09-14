// 00455060 FUN_00455060 [Global]
// programa: gamma.dll

int * __cdecl FUN_00455060(LPCSTR param_1,char *param_2,int *param_3)

{
  int iVar1;
  undefined4 local_8;
  
  FUN_00459570();
  if (param_3 == (int *)0x0) {
    return (int *)0x0;
  }
  FUN_00454eb0(param_3);
  FUN_00459560((int)param_3);
  iVar1 = FUN_00455120((byte)&local_8,param_2,(ushort *)&local_8);
  if (iVar1 == 0) {
    return (int *)0x0;
  }
  FUN_00454be0(param_3,local_8,(uint *)0x0,0x1000);
  iVar1 = FUN_00459110(param_1,local_8,param_3);
  if (iVar1 != 0) {
    *(ushort *)(param_3 + 1) = *(ushort *)(param_3 + 1) & 0xfc7f;
    if ((*(byte *)(param_3 + 2) >> 3 & 1) != 0) {
      FUN_00454a60((undefined4 *)param_3[8]);
    }
    return (int *)0x0;
  }
  if (((byte)local_8 >> 2 & 4) != 0) {
    FUN_004553b0(param_3,0,2);
  }
  return param_3;
}


