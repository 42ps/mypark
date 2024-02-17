#[rustfmt::skip]
const CLOCK_SWITCH: [[Option<usize>; 5]; 10] = [
	[ Some(0), Some(1), Some(2),  None,     None] ,
	[ Some(3), Some(7), Some(9),  Some(11), None] ,
	[ Some(4), Some(0), Some(4),  Some(15), None] ,
	[ Some(0), Some(4), Some(5),  Some(6),  Some(7)] ,
	[ Some(6), Some(7), Some(8),  Some(0),  Some(12)] ,
	[ Some(0), Some(2), Some(4),  Some(15), None] ,
	[ Some(3), Some(4), Some(15), None,     None] ,
	[ Some(4), Some(5), Some(7),  Some(4),  Some(15)] ,
	[ Some(1), Some(2), Some(3),  Some(4),  Some(5)] ,
	[ Some(3), Some(4), Some(5),  Some(9),  Some(13)] ,
];
fn main() {
	println!("Hello, world!");
}
