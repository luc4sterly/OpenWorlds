// 004240d0 FUN_004240d0 [Global]
// programa: gamma.dll

uint __fastcall FUN_004240d0(int param_1)

{
  uint uVar1;
  
  if (*(byte **)(param_1 + 8) < *(byte **)(param_1 + 0xc)) {
    uVar1 = (uint)**(byte **)(param_1 + 8);
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


