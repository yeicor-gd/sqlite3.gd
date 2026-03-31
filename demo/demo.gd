extends Node
class_name Demo

func _ready():
	# Start with autowrapper tests
	TestAutowrapper.run()
	print("Demo finished successfully")
