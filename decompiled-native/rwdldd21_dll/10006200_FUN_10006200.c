// 10006200 FUN_10006200 [Global]
// programa: RWDLDD21.DLL

void FUN_10006200(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined1 *puStack_a8;
  int *piStack_a4;
  int iStack_a0;
  int iStack_9c;
  int iStack_98;
  
  puVar6 = *(undefined4 **)(param_1 + 0xa0);
  if (puVar6[0xb] == 0) {
    FUN_100033a0(puVar6);
  }
  piVar1 = (int *)puVar6[0xb];
  if (piVar1 != (int *)0x0) {
    puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x100) + 0x2c);
    if (((piVar1[5] != DAT_10038b48) || (piVar1[6] != DAT_10038b4c)) || (piVar1[7] != DAT_10038b50))
    {
      iStack_98 = 0x10006291;
      piVar3 = FUN_10006450((int *)*piVar1);
      if (piVar3 != (int *)0x0) {
        if ((int *)*piVar1 != (int *)0x0) {
          (**(code **)(*(int *)*piVar1 + 8))();
          *piVar1 = 0;
        }
        *piVar1 = (int)piVar3;
        puVar6[1] = DAT_10038b44;
        *puVar6 = 2;
        puVar6[2] = DAT_10038b48;
        puVar6[4] = DAT_10038b4c;
        puVar6[3] = DAT_10038b50;
        puVar6[5] = DAT_10038b54;
        piVar5 = &DAT_10038b38;
        piVar3 = piVar1;
        for (iVar4 = 8; piVar3 = piVar3 + 1, iVar4 != 0; iVar4 = iVar4 + -1) {
          *piVar3 = *piVar5;
          piVar5 = piVar5 + 1;
        }
      }
    }
    piStack_a4 = (int *)*puVar2;
    iStack_98 = *piVar1;
    iStack_9c = DAT_10042038 + param_4;
    iStack_a0 = DAT_10042034 + param_3;
    puStack_a8 = (undefined1 *)0x1000631c;
    iVar4 = (**(code **)(*piStack_a4 + 0x1c))();
    if (iVar4 == -0x7789fe3e) {
      puStack_a8 = &LAB_10001b40;
      puVar6 = (undefined4 *)&stack0xffffff7c;
      for (iVar4 = 0x1b; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
      }
      (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,&stack0xffffff7c,0);
      if (DAT_10036038 != (int *)0x0) {
        (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
      }
      if (DAT_1003603c != DAT_10036038) {
        (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
      }
      (**(code **)(*(int *)*puVar2 + 0x1c))
                ((int *)*puVar2,DAT_10042034 + param_3,DAT_10042038 + 0x4000,*piVar1,&puStack_a8,
                 0x10);
    }
    do {
      puStack_a8 = (undefined1 *)0x2;
      iVar4 = (**(code **)(*(int *)*puVar2 + 0x34))((int *)*puVar2);
      if (iVar4 == -0x7789fe3e) {
        puStack_a8 = &LAB_10001b40;
        puVar6 = (undefined4 *)&stack0xffffff7c;
        for (iVar4 = 0x1b; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar6 = 0;
          puVar6 = puVar6 + 1;
        }
        (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,&stack0xffffff7c,0);
        if (DAT_10036038 != (int *)0x0) {
          (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
        }
        if (DAT_1003603c != DAT_10036038) {
          (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
        }
        iVar4 = (**(code **)(*(int *)*puVar2 + 0x34))((int *)*puVar2,2);
      }
    } while (iVar4 != 0);
  }
  return;
}


