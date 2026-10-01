// 0041c156 FUN_0041c156 [Global]
// program: sfmain.exe

void __fastcall FUN_0041c156(undefined4 param_1,int param_2)

{
  int unaff_EBX;
  undefined1 local_38 [20];
  uint local_14;
  undefined4 local_10;
  
  local_14 = 0x10;
  local_10 = param_1;
  if (param_2 == -1) {
    FUN_00421cb2(local_38,&local_14);
  }
  else {
    local_10._0_2_ = (short)param_1;
    if (((short)local_10 == 1) && (unaff_EBX == 0)) {
      FUN_00429a76();
    }
  }
  return;
}


