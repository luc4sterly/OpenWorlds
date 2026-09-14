// 0040aa30 FUN_0040aa30 [Global]
// programa: gamma.dll

void FUN_0040aa30(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = DAT_004890f8;
  iVar2 = (**(code **)(*DAT_004890f8 + 0x18))(DAT_004890f8,s_NET_worlds_console_ActiveX_0046e284);
  if (iVar2 == 0) {
    FUN_00402930(piVar1,(byte *)s_java_io_IOException_0046e090,
                 s_Unabled_to_locate_ActiveX_class_0046e2a0);
    return;
  }
  iVar3 = (**(code **)(*piVar1 + 0x1c4))(piVar1,iVar2,s_incServerLocks_0046e2c8,&DAT_0046e2c0);
  if (iVar3 == 0) {
    FUN_00402930(piVar1,(byte *)s_java_io_IOException_0046e090,
                 s_Unabled_to_locate_ActiveX_incSer_0046e2d8);
    return;
  }
  FUN_00402bd0(piVar1,iVar2,iVar3);
  return;
}


