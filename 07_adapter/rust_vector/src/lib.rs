pub struct RustI32Vector
{
    inner: Vec<i32>,
}

#[unsafe(no_mangle)]
pub extern "C" fn rust_i32_vector_new() -> *mut RustI32Vector
{
    let inner = Vec::<i32>::new();
    Box::into_raw(Box::new(RustI32Vector { inner }))
}

#[unsafe(no_mangle)]
pub extern "C" fn rust_i32_vector_delete(ptr: *mut RustI32Vector)
{
    if !ptr.is_null()
    {
        unsafe
        {
            let r_vector = Box::from_raw(ptr);
            drop(r_vector);
        }
    }
}

#[unsafe(no_mangle)]
pub extern "C" fn rust_i32_vector_push(ptr: *mut RustI32Vector, value: i32)
{
    if ptr.is_null() {return}

    let v = unsafe {&mut *ptr};
    v.inner.push(value);
}

#[unsafe(no_mangle)]
pub extern "C" fn rust_i32_vector_get(v: &mut RustI32Vector, index: usize) -> &mut i32
{
    assert!(index < v.inner.len(), "in rust_i32_vector_get");
    &mut v.inner[index]
}

#[unsafe(no_mangle)]
pub extern "C" fn rust_i32_vector_len(ptr: *mut RustI32Vector) -> usize
{
    if ptr.is_null() {return 0}

    let v = unsafe {&mut *ptr};

    v.inner.len()
}

#[unsafe(no_mangle)]
pub extern "C" fn rust_i32_vector_data_start(ptr: *mut RustI32Vector) -> *mut i32
{
    if ptr.is_null() {return std::ptr::null_mut()}

    let v = unsafe {&mut *ptr};

    v.inner.as_mut_ptr()
}

    
