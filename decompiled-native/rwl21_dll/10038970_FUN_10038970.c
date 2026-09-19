// 10038970 FUN_10038970 [Global]
// programa: RWL21.DLL

int FUN_10038970(uint param_1)

{
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  for (local_c = 1; local_c != 0; local_c = local_c << 1) {
    if ((param_1 & local_c) != 0) {
      local_8 = local_8 + 1;
    }
  }
  return local_8;
}


