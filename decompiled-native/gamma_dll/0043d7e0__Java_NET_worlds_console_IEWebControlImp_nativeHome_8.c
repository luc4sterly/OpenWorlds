// 0043d7e0 _Java_NET_worlds_console_IEWebControlImp_nativeHome@8 [Global]
// program: gamma.dll

void _Java_NET_worlds_console_IEWebControlImp_nativeHome_8(int *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  uint *puVar6;
  
                    /* 0x3d7e0  36  _Java_NET_worlds_console_IEWebControlImp_nativeHome@8 */
  uVar2 = (**(code **)(*param_1 + 0x7c))(param_1,param_2);
  iVar3 = (**(code **)(*param_1 + 0x178))(param_1,uVar2,s_nativeIEInstance_00477524,&DAT_00477520);
  if (iVar3 == 0) {
    FUN_00402800(s_nIEWebControlImp_00477538,0x53);
  }
  puVar4 = (uint *)(**(code **)(*param_1 + 400))(param_1,param_2,iVar3);
  if (puVar4 == (uint *)0x0) {
    puVar4 = FUN_0044e010(0x3c);
    puVar6 = puVar4;
    for (iVar5 = 0xf; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    (**(code **)(*param_1 + 0x1b4))(param_1,param_2,iVar3,puVar4);
  }
  piVar1 = (int *)puVar4[3];
  if (piVar1 == (int *)0x0) {
    return;
  }
  (**(code **)(*piVar1 + 0x24))(piVar1);
  return;
}


