// 0044d5a0 FUN_0044d5a0 [Global]
// program: gamma.dll

byte * __cdecl FUN_0044d5a0(char *param_1)

{
  int iVar1;
  byte *pbVar2;
  
  iVar1 = FUN_004553d0(0x4824bc,-1);
  if (-1 < iVar1) {
    return (byte *)0xffffffff;
  }
  pbVar2 = FUN_0044ce70(&LAB_0044d520,&DAT_004824bc,param_1,
                        (uint *)(&param_1 +
                                ((int)(&stack0x0000000b + -(int)&param_1 +
                                      ((int)(&stack0x0000000b + -(int)&param_1) >> 0x1f & 3)) >> 2))
                       );
  return pbVar2;
}


