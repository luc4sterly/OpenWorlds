// 00451410 FUN_00451410 [Global]
// programa: gamma.dll

void FUN_00451410(int *param_1,int *param_2,ushort *param_3)

{
  int *piVar1;
  
  FUN_00450ff0(param_1,param_2,param_3);
  piVar1 = (int *)(param_1[3] + *(int *)(param_3 + 4));
  *piVar1 = param_1[6];
  piVar1[1] = param_1[5];
  piVar1[2] = param_1[7];
  piVar1[5] = (int)param_3;
                    /* WARNING: Could not recover jumptable at 0x0045146c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(param_3 + 2))();
  return;
}


