// 00440900 FUN_00440900 [Global]
// program: gamma.dll

undefined4 __fastcall FUN_00440900(int param_1)

{
  int iVar1;
  undefined4 local_78 [2];
  undefined4 local_70;
  undefined4 local_6c;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0x24) + 0x10))
                    (*(int **)(param_1 + 0x24),&DAT_004671c8,param_1 + 0x28);
  if (-1 < iVar1) {
    iVar1 = (**(code **)**(undefined4 **)(param_1 + 0x28))
                      (*(undefined4 **)(param_1 + 0x28),&DAT_00467148,param_1 + 0x2c);
    if (-1 < iVar1) {
      local_78[0] = 0x6c;
      iVar1 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x24))
                        (*(int **)(param_1 + 0x2c),local_78,0,0,0);
      if (-1 < iVar1) {
        *(undefined4 *)(param_1 + 0x40) = 0;
        *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(param_1 + 0x40);
        *(undefined4 *)(param_1 + 0x4c) = local_70;
        *(undefined4 *)(param_1 + 0x48) = local_6c;
        iVar1 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x34))
                          (*(int **)(param_1 + 0x2c),*(undefined4 *)(param_1 + 0x1c),param_1 + 0x40,
                           0,param_1 + 0x30);
      }
    }
  }
  if (iVar1 < 0) {
    FUN_0044d5a0(s_Initialization_failure_in_InitRe_00478258);
    FUN_0044d5a0(&DAT_004780c8);
    return 0x80004005;
  }
  return 0;
}


