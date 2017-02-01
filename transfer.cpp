:: global UI state stores latent (past) user input. eg, the type of panel that has the focus of the user currently.
:: from raw input and global UI state, get an action the user intends to perform,

:: @user_action_get,
	:: for all raw inputs queued,
	:: is there a key release?
		:: then go through the list removing matching key presses. (making them null)
		:: compress the queue if removals have happened.
	:: convert the screen position from raw_input into an application's position as integers x,y
	:: origin of coordinates for the screen being a corner (probable top-left corner)
	:: while the raw input queue is not empty,
		:: is input a left mouse button or a tip of tablet pen click?
			:: get panel id under the click,
			:: is the panel id different than the currently focused panel?
; 				:: then we need to change the focus to the panel with that ID, @panel_give_focus.
:: @panel_give_focus,
	:: <...>

; 			:: call @selection_start.
:: @selection_start,
	:: <...>

		:: scan through all stored bindings, comparing the current key queue.
			:: is the first key press in the queue matching any key_bindings?
				:: then make a list with those.
				:: is the second key press in the queue not matching a key_binding in the list?
					:: cull the entry ( make it null )
					:: 

	:: are the keys "CTRL", "ALT"  and a directional key (UP, DOWN, LEFT, RIGHT) pressed together?
		:: is the event creating or destroying a panel?
		:: is the key "SHIFT" also pressed?
			:: then we write a #newDivision struct
				:: <@sync>panel_add_remove
				struct div nextDivisionAction = div(...);
		:: else we are removing a panel
				:: <@sync>panel_add_remove
				struct div nextDivisionAction = div(...);
	
	:: @panel_add_remove
		:: <...>
		:: now also change the focus accordingly, 
			:: if creating a new panel change the focus to that.
			:: if removing the panel we are in, change the focus to the parent panel.
	:: else ( the focus is not an issue then )
		:: switch to [ current focused Panel in visualObjectDatabase ], 
		switch(focusedPanel.type){
			:: case [ nodeGraph panel ],
				:: is input a single writable character (also includes the Backspace)?
					:: is there a createNode NOT selected? ( it also means it does not exist ).
						:: create a createNode. 
						:: (for the backspace character this brings up an empty createNode).
						:: copy the input into it.
				:: trigger a fSearch for possible node names for this createNode.
					:: then, 
						:: copy the input into it,
				:: update current createNode fSearch for possible node names.
				:: else is input more than one writable character?
					:: then ASSERT ( can't decide which one should go first ).
			:: case [ textEditor panel ], 
				:: is input a writable character (also includes erasing character like Backspace or DEL)?
					:: write the input into the buffer pointed by the vBuffer of the pane.
						:: <...>
					:: mark_vBuffer_dirty. <async>
					:: change the UI state data, in this case the caret position
				:: else it is a navigation input.
					:: we could manage all inputs under a main switch like this, <...>alternatives?
					:: switch [ ] { 
						:: case [ is nav. going up / down one line ] 
						:: case [ is nav. going up / down one paragraph ] 
						:: case [ is nav. going up / down one page ] 
						:: case [ is nav. going to the start / end of the buffer line ] 
						:: case [ is nav. going left / right one character ] 
						:: case [ is nav. going left / right one token ] 
						:: case [ is nav. going left / right to character border ] 
						:: case [ is nav. going to the start / end of the line]
						
						:: case [ is the caret position following navigation? ]
						:: case [ is selection following navigation? ]
					 
					:: or we could keep specializing the response based on the particulars of the pInput
					:: is input also impliying selection
						:: <...>
					:: else 
						:: change the caret position to the new position as calculated by navigation strategies.
							:: <...>
						:: we update the virtual buffer to follow the navigation
							:: is the vBuffer content changed based on the horizontal and vertical navigation strategies?
							:: <...>
			:: case <...>


	:: using the structure that defines the panels in the application, @panel_get_index,
	:: switch [ panel_type ],
		:: case [ text_panel ]:
		:: <...>
		:: case [ graph_panel ]:
		:: <...>
		:: case [ sketch_panel ]:
		:: <...>

:: ???
uh, no, solo hacemos esto si estamos dibujando...
	:: store into positional history array, #positionHistory
	:: <...>

:: #positionHistory,
:: array of 300 floats x,y,
	float array[300*2]~
