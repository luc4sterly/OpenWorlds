// 00406120 FUN_00406120 [Global]
// program: gamma.dll

void FUN_00406120(uint param_1,int *param_2,uint param_3)

{
  if (param_3 < 10) {
    (**(code **)(*param_2 + 0x14))(param_3 + 0x30);
    return;
  }
  if ((param_1 & 0x4000) != 0) {
    (**(code **)(*param_2 + 0x14))(param_3 + 0x37);
    return;
  }
  (**(code **)(*param_2 + 0x14))(param_3 + 0x57);
  return;
}


