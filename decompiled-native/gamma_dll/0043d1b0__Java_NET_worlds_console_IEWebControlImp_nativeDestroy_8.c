// 0043d1b0 _Java_NET_worlds_console_IEWebControlImp_nativeDestroy@8 [Global]
// programa: gamma.dll

void _Java_NET_worlds_console_IEWebControlImp_nativeDestroy_8(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint *puVar3;
  int *piVar4;
  int iVar5;
  uint *puVar6;
  int *local_18;
  int *local_14;
  
                    /* 0x3d1b0  32  _Java_NET_worlds_console_IEWebControlImp_nativeDestroy@8 */
  uVar1 = (**(code **)(*param_1 + 0x7c))(param_1,param_2);
  iVar2 = (**(code **)(*param_1 + 0x178))(param_1,uVar1,s_nativeIEInstance_00477524,&DAT_00477520);
  if (iVar2 == 0) {
    FUN_00402800(s_nIEWebControlImp_00477538,0x53);
  }
  puVar3 = (uint *)(**(code **)(*param_1 + 400))(param_1,param_2,iVar2);
  if (puVar3 == (uint *)0x0) {
    puVar3 = FUN_0044e010(0x3c);
    puVar6 = puVar3;
    for (iVar5 = 0xf; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    (**(code **)(*param_1 + 0x1b4))(param_1,param_2,iVar2,puVar3);
  }
  piVar4 = (int *)puVar3[3];
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 8))(piVar4);
  }
  if ((HWND)puVar3[0xb] != (HWND)0x0) {
    DestroyWindow((HWND)puVar3[0xb]);
  }
  local_18 = (int *)0x0;
  piVar4 = (int *)FUN_0043e960(puVar3[2]);
  if (piVar4 != (int *)0x0) {
    iVar2 = (**(code **)*piVar4)(piVar4,&DAT_00467028,&local_14);
    if (-1 < iVar2) {
      (**(code **)(*local_14 + 0x10))(local_14,&DAT_00466e70,&local_18);
      (**(code **)(*local_14 + 8))(local_14);
    }
    (**(code **)(*piVar4 + 8))(piVar4);
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 0x18))(local_18,puVar3[4]);
      (**(code **)(*local_18 + 8))(local_18);
    }
  }
  piVar4 = (int *)puVar3[5];
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 8))(piVar4);
  }
  piVar4 = (int *)puVar3[6];
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 8))(piVar4);
  }
  if (puVar3[2] != 0) {
    FUN_0043e730(puVar3[2]);
    (**(code **)(*(int *)puVar3[2] + 8))((int *)puVar3[2]);
  }
  if ((undefined4 *)puVar3[0xc] != (undefined4 *)0x0) {
    FUN_0044e100((undefined4 *)puVar3[0xc]);
  }
  (**(code **)(*param_1 + 0x58))(param_1,puVar3[0xe]);
  FUN_0044e100(puVar3);
  return;
}


