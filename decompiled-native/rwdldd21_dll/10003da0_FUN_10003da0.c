// 10003da0 FUN_10003da0 [Global]
// programa: RWDLDD21.DLL

void FUN_10003da0(int *param_1)

{
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  if (DAT_1003606c != 0) {
    FUN_10029ab0();
    DAT_1003606c = 0;
  }
  if (*(int *)(DAT_1003a024 + 4) != 0) {
    FUN_10001080(DAT_1003a024);
    local_10 = *param_1 + DAT_10042034;
    local_c = param_1[1] + DAT_10042038;
    local_8 = param_1[2] + local_10;
    local_4 = param_1[3] + local_c;
    (**(code **)(**(int **)(DAT_1003a024 + 0xc) + 0x30))
              (*(int **)(DAT_1003a024 + 0xc),1,&local_10,2);
  }
  return;
}


