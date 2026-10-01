// 10046e50 get_int_arg [Global]
// program: RWL21.DLL

/* Library Function - Single Match
    _get_int_arg
   
   Library: Visual Studio 1998 Release */

undefined4 __cdecl get_int_arg(int *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)*param_1;
  *param_1 = (int)(puVar1 + 1);
  return *puVar1;
}


