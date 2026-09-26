// 10002880 FUN_10002880 [Global]
// programa: RWDLDD21.DLL

undefined4 FUN_10002880(int *param_1,int *param_2,int param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *unaff_EDI;
  undefined4 *puVar4;
  int *local_88;
  int local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  int local_74;
  int local_70;
  undefined4 auStack_6c [26];
  undefined4 uStack_4;
  
  local_80 = 0x401000;
  if (param_3 == 0) {
    local_84 = 1;
  }
  else {
    local_84 = param_4[10];
  }
  iVar3 = 0;
  if (0 < local_84) {
    do {
      if (iVar3 != 0) {
        iVar1 = (**(code **)(*param_2 + 0x30))(param_2,&local_80,&local_88);
        param_2 = unaff_EDI;
        if (iVar1 != 0) {
          param_2 = (int *)0x0;
        }
        iVar1 = (**(code **)(*param_1 + 0x30))(param_1,&stack0xffffff74,&stack0xffffff6c);
        param_1 = local_88;
        unaff_EDI = param_2;
        if (iVar1 != 0) {
          local_88 = (int *)0x0;
          param_1 = local_88;
        }
      }
      local_78 = 0;
      local_74 = *param_4 >> ((byte)iVar3 & 0x1f);
      local_7c = 0;
      local_70 = local_74;
      iVar1 = (**(code **)(*param_1 + 0x14))(param_1,&local_7c,param_2,&local_7c,0x1000000,0);
      if (iVar1 == -0x7789fe3e) {
        puVar4 = auStack_6c;
        for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar4 = 0;
          puVar4 = puVar4 + 1;
        }
        auStack_6c[0] = 0x6c;
        auStack_6c[1] = 1;
        uStack_4 = 0x4000;
        (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,auStack_6c,0,&LAB_10001b40);
        if (DAT_10036038 != (int *)0x0) {
          (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
        }
        if (DAT_1003603c != DAT_10036038) {
          (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
        }
        iVar1 = (**(code **)(*param_1 + 0x14))
                          (param_1,&stack0xffffff70,param_2,&stack0xffffff70,0x1000000,0);
      }
      if (iVar1 != 0) {
        iVar2 = FUN_10001ef0(param_1,param_2);
        if (iVar2 != 0) {
          iVar1 = 0;
        }
        if (iVar1 != 0) {
          return 0;
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < local_84);
  }
  return 1;
}


