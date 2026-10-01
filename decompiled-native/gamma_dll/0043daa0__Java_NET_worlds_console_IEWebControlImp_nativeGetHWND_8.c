// 0043daa0 _Java_NET_worlds_console_IEWebControlImp_nativeGetHWND@8 [Global]
// program: gamma.dll

uint _Java_NET_worlds_console_IEWebControlImp_nativeGetHWND_8(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  
                    /* 0x3daa0  33  _Java_NET_worlds_console_IEWebControlImp_nativeGetHWND@8 */
  uVar1 = (**(code **)(*param_1 + 0x7c))(param_1,param_2);
  iVar2 = (**(code **)(*param_1 + 0x178))(param_1,uVar1,s_nativeIEInstance_00477524,&DAT_00477520);
  if (iVar2 == 0) {
    FUN_00402800(s_nIEWebControlImp_00477538,0x53);
  }
  puVar3 = (uint *)(**(code **)(*param_1 + 400))(param_1,param_2,iVar2);
  if (puVar3 == (uint *)0x0) {
    puVar3 = FUN_0044e010(0x3c);
    puVar5 = puVar3;
    for (iVar4 = 0xf; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    (**(code **)(*param_1 + 0x1b4))(param_1,param_2,iVar2,puVar3);
  }
  return puVar3[1];
}


