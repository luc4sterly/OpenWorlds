// 00457ff0 FUN_00457ff0 [Global]
// programa: gamma.dll

void FUN_00457ff0(int *param_1,int param_2)

{
  if (param_1[1] != -1) {
                    /* WARNING: Could not recover jumptable at 0x0045800b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)(param_2 + *param_1 + param_1[2]) + param_1[1]))();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00458010. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)param_1[2])();
  return;
}


