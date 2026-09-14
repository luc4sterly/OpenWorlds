// 0043ce30 _Java_NET_worlds_console_IEWebControlImp_nativeInit@16 [Global]
// programa: gamma.dll

undefined4
_Java_NET_worlds_console_IEWebControlImp_nativeInit_16
          (int *param_1,undefined4 param_2,uint param_3,byte param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  int *local_18;
  int *local_14;
  
                    /* 0x3ce30  37  _Java_NET_worlds_console_IEWebControlImp_nativeInit@16 */
  uVar2 = (**(code **)(*param_1 + 0x7c))(param_1,param_2);
  iVar3 = (**(code **)(*param_1 + 0x178))(param_1,uVar2,s_nativeIEInstance_00477524,&DAT_00477520);
  if (iVar3 == 0) {
    FUN_00402800(s_nIEWebControlImp_00477538,0x53);
  }
  puVar4 = (uint *)(**(code **)(*param_1 + 400))(param_1,param_2,iVar3);
  if (puVar4 == (uint *)0x0) {
    puVar4 = FUN_0044e010(0x3c);
    puVar5 = puVar4;
    for (iVar8 = 0xf; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    (**(code **)(*param_1 + 0x1b4))(param_1,param_2,iVar3,puVar4);
  }
  if (puVar4[2] != 0) {
    FUN_00402800(s_nIEWebControlImp_00477538,0x69);
  }
  puVar5 = FUN_0044e010(0x3c);
  if (puVar5 != (uint *)0x0) {
    FUN_0043dd70(puVar5);
  }
  puVar4[2] = (uint)puVar5;
  puVar5 = FUN_0044e010(8);
  if (puVar5 != (uint *)0x0) {
    *puVar5 = (uint)puVar4;
    puVar5[1] = 0;
  }
  puVar4[0xc] = (uint)puVar5;
  puVar5 = FUN_0044e010(0xc);
  if (puVar5 != (uint *)0x0) {
    FUN_0043cc20(puVar5,puVar4[0xc]);
  }
  puVar4[5] = (uint)puVar5;
  puVar4[1] = param_3;
  puVar4[0xd] = (uint)param_1;
  uVar6 = (**(code **)(*param_1 + 0x54))(param_1,param_2);
  puVar4[0xe] = uVar6;
  if ((void *)puVar4[2] != (void *)0x0) {
    FUN_0043e7c0((void *)puVar4[2],param_3);
    FUN_0043e990((void *)puVar4[2],(uint)param_4);
    FUN_0043e690(puVar4[2]);
    FUN_0043e850((void *)puVar4[2],1);
    FUN_0043e8f0((void *)puVar4[2],0);
    piVar7 = (int *)FUN_0043e960(puVar4[2]);
    if (piVar7 != (int *)0x0) {
      iVar3 = (**(code **)*piVar7)(piVar7,&DAT_00466e80,puVar4 + 3);
      if (iVar3 < 0) {
        (**(code **)*piVar7)(piVar7,&DAT_00466ea0,puVar4 + 3);
        puVar4[10] = 1;
      }
      (**(code **)(*piVar7 + 8))(piVar7);
    }
    puVar1 = (undefined4 *)puVar4[3];
    if (puVar1 == (undefined4 *)0x0) {
      uVar6 = _Java_NET_worlds_console_IEWebControlImp_nativeDestroy_8(param_1,param_2);
      return uVar6 & 0xffffff00;
    }
    (**(code **)*puVar1)(puVar1,&DAT_00466f88,puVar4 + 6);
    piVar7 = (int *)FUN_0043e960(puVar4[2]);
    if (piVar7 == (int *)0x0) {
      return 0;
    }
    local_14 = (int *)0x0;
    local_18 = (int *)0x0;
    iVar3 = (**(code **)*piVar7)(piVar7,&DAT_00467028,&local_14);
    if (-1 < iVar3) {
      if (local_14 != (int *)0x0) {
        (**(code **)(*local_14 + 0x10))(local_14,&DAT_00466e70,&local_18);
        (**(code **)(*local_14 + 8))(local_14);
      }
      if (local_18 != (int *)0x0) {
        (**(code **)(*local_18 + 0x14))(local_18,puVar4[5],puVar4 + 4);
        (**(code **)(*local_18 + 8))(local_18);
      }
    }
    uVar6 = (**(code **)(*piVar7 + 8))(piVar7);
  }
  return CONCAT31((int3)(uVar6 >> 8),1);
}


