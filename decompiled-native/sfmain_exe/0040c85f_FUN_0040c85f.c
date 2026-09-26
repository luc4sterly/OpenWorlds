// 0040c85f FUN_0040c85f [Global]
// programa: sfmain.exe

void __fastcall FUN_0040c85f(undefined4 param_1,float *param_2)

{
  int in_EAX;
  float *pfVar1;
  int iVar2;
  float *unaff_EBX;
  float local_c;
  
  local_c = 0.0;
  pfVar1 = param_2;
  for (iVar2 = 1; pfVar1 = pfVar1 + 1, iVar2 <= in_EAX; iVar2 = iVar2 + 1) {
    local_c = local_c + *pfVar1;
  }
  iVar2 = 1;
  while( true ) {
    param_2 = param_2 + 1;
    unaff_EBX = unaff_EBX + 1;
    if (in_EAX < iVar2) break;
    iVar2 = iVar2 + 1;
    *unaff_EBX = *param_2 - local_c / (float)in_EAX;
  }
  return;
}


