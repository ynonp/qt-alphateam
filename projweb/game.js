/**
 * Created by JetBrains WebStorm.
 * User: ynonperek
 * Date: 2/29/12
 * Time: 2:28 PM
 * To change this template use File | Settings | File Templates.
 */

(function(global) {
    var NUM_COLS = 3, NUM_ROWS = 3;
    var EMPTY_CARD = '#CCC';


    var cards = document.querySelectorAll('div.span4');

    for ( var i=0; i < cards.length; i++ ) {
        // assign row and col values to each card
        cards[i].setAttribute('zombie-row', Math.floor(i / NUM_ROWS));
        cards[i].setAttribute('zombie-col', Math.floor(i % NUM_COLS));
    }


    global.cards = cards;

    var Qt = {
        card_selected: function(row, col) {
            // calling C++ Code
        }
    };

    document.querySelector('#container').addEventListener('click', function(e) {
        if ( e.srcElement.className === 'span4' ) {
            var card = e.srcElement;
            var row = Number(card.getAttribute('zombie-row'));
            var col = Number(card.getAttribute('zombie-col'));
            if ( ! ( isNaN(row) || isNaN(col) ) ) {
                Qt.card_selected(row, col);
            }
        }
    });


    /**
     * All of these functions will be called from C++ by
     * binding them to signals
     */
    global.EventHandlers = {
        reveal_card : function(row, col, img) {
            var card = cards[row * NUM_COLS + col];



            if ( img && img.toDataUrl ) {

                window.dbg = img;
                window.card = card;
                card.style.background = 'url(' + img.toDataUrl() + ')';
            } else {
                card.style.background = 'red';
            }
        },

        hide_cards_array: function(cards_to_hide) {
            var row, col;

            for ( var i=0; i < cards_to_hide.length; i += 1 ) {
                row = cards_to_hide[i].row;
                col = cards_to_hide[i].col;

                cards[row * NUM_COLS + col].style.background = EMPTY_CARD;
            }
        }

    };

    global.init = function() {
        me.revealCard.connect(global.EventHandlers.reveal_card);
    };





}(this));

